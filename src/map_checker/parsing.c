/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:13:30 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/09 14:01:29 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->collectable = 0;
	map->design = NULL;
	map->player = 0;
	map->floor = 0;
	map->exit = 0;
}

void	map_height(char *file_name, t_map *map)
{
	int	fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		free(line);
		map->height++;
	}
	close(fd);
}

void	map_read(char *file_name, t_map *map)
{
	int	fd;
	int	i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return ;
	map->design = malloc((map->height - 1) * sizeof(char *));
	if (!map->design)
	{
		close (fd);
		return ;
	}
	i = 0;
	while ((map->design[i] = get_next_line(fd)))
		i++;
	map->design = NULL;
	close(fd);
}

int map_shape(t_map *map)
{
	int i;

	i = 0;
	while(i < )
}