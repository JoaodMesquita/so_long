/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpmesquita <jpmesquita@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:35:55 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/12 10:39:02 by jpmesquita       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_position(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->design[y][x] == 'P')
			{
				map->start_x = x;
				map->start_y = y;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->width || y > map->height)
		return ;
	if (map->design[y][x] == '1' || map->design[y][x] == 'F')
		return ;
	if (map->design[y][x] == 'C')
	{
		map->design[y][x] = 'F';
		map->collectable -= 1;
	}
	if (map->design[y][x] == 'E')
	{
		map->design[y][x] = 'F';
		map->exit -= 1;
		return ;
	}
	map->design[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

int	valid_exit(t_map *map, char *file_name)
{
	int	collectable;

	collectable = map->collectable;
	player_position(map);
	flood_fill(map, map->start_x, map->start_y);
	free_map(map);
	map_read(file_name, map);
	if (map->collectable != 0 || map->exit)
	{
		ft_printf("Error\nInvalid path\n");
		return (0);
	}
	map->collectable = collectable;
	map->exit = 1;
	return (1);
}
