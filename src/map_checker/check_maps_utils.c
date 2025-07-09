/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:29:31 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/09 13:49:06 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_args(int ac)
{
	if (ac == 2)
		return (0);
	else
	{
		ft_printf("Error\nNot enough arguments!\n");
		return (1);
	}
}

int	map_valid(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width - 1)
	{
		y = 0;
		while (y < map->height - 1)
		{
			if (map->design[x][y] == 'C')
				map->collectable++;
			else if (map->design[x][y] == 'P')
				map->player++;
			else if (map->design[x][y] == 'E')
				map->exit++;
			y++;
		}
		x++;
	}
	if (map->collectable < 1 || map->player != 1 || map->exit != 1)
	{
		ft_printf("Invalid Map!");
		return (0);
	}
	return (1);
}

int	check_map_name(char *file_name)
{
	if (ft_strrchr(file_name, '/'))
	{
		file_name = ft_strrchr(file_name, '/');
		file_name++;
	}
	if (!ft_strncmp(file_name, ".ber", 5))
	{
		ft_printf("Error\n'file must have a name prefix (e.g., 'map.ber').\n");
		return (1);
	}
	file_name = ft_strrchr(file_name, '.');
	if (ft_strncmp(file_name, ".ber", 5))
	{
		ft_printf("Error\nInvalid map name OLAAA!\n");
		return (1);
	}
	return (0);
}

int	walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width -1)
	{
		y = 0;
		while (y < map-> height -1)
		{
			if (map->design[x][0] != 1)
				return (0);
			if (map->design[x][map->height -1] != 1)
				return (0);
			if (map->design[0][y] != 1)
				return (0);
			if (map->design[map->width -1][y] != 1)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	check_min_characters(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map ->height)
		{
			if (map->design[x][y] != '0' && map->design[x][y] != '1'
			&& map->design[x][y] != 'P' && map->design[x][y] != 'C'
			&& map->design[x][y] != 'E')
			{
				ft_printf("Error\n Invalid characters!\n");
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
