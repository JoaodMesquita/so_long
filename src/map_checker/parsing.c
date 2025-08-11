/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:13:30 by joapedro          #+#    #+#             */
/*   Updated: 2025/08/11 13:47:28 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_fd(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDWR);
	if (fd < 0)
	{
		ft_printf("No such file: '%s'", file_name);
		return (0);
	}
	close (fd);
	return (1);
}

void	map_height(char *file_name, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (exit(1));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		map->height++;
	}
	if (map->height == 0)
	{
		close(fd);
		ft_printf("Error\nEmpty file\n");
		return (exit(1));
	}
	close(fd);
}

void	map_read(char *file_name, t_map *map)
{
	int	fd;
	int	i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (exit(1));
	map->design = malloc(map->height * sizeof(char *));
	if (!map->design)
	{
		close (fd);
		return ;
	}
	i = 0;
	while (i < map->height)
	{
		map->design[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	map_shape(t_map *map)
{
	int	i;
	int	width;

	i = -1;
	while (++i < map->height - 1)
		str_trim(map->design[i]);
	i = 0;
	width = ft_strlen(map->design[i]);
	while (i < map->height)
	{
		if ((width != ft_strlen(map->design[i]) && (map->design[i] != NULL)))
		{
			ft_printf("Error\nMap is not rectangular.\n");
			return (0);
		}
		i++;
	}
	map->width = width;
	if ((map->width < 5 && map->height < 3)
		|| (map->width < 3 && map->height < 5))
	{
		ft_printf("Error\nMap is not rectangular.\n");
		return (0);
	}
	return (1);
}

int	check_map(int ac, char **av, t_map *map)
{
	if (!check_args(ac))
		return (0);
	if (!check_fd(av[1]))
		return (0);
	if (!check_map_name(av[1]))
		return (0);
	initialize(map);
	map_height(av[1], map);
	map_read(av[1], map);
	if (!map_shape(map))
		return (0);
	if (!check_min_characters(map))
		return (0);
	if (!check_characters(map))
		return (0);
	if (!walls(map))
	{
		ft_printf("Error\nInvalid Walls\n");
		return (0);
	}
	if (!valid_exit(map, av[1]))
		return (0);
	return (1);
}
