/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:25:47 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/29 15:03:06 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_args(int ac)
{
	if (ac == 2)
		return (1);
	else
	{
		ft_printf("Error\nNo Map!\n");
		return (0);
	}
}

int	check_min_characters(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->design[y][x] == 'C')
				map->collectable++;
			else if (map->design[y][x] == 'P')
				map->player++;
			else if (map->design[y][x] == 'E')
				map->exit++;
			x++;
		}
		y++;
	}
	if (map->collectable < 1 || map->player != 1 || map->exit != 1)
	{
		ft_printf("Error\nMust have player, exit and at least 1 collectable\n");
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
		ft_printf("Error\nInvalid map name\n");
		return (0);
	}
	file_name = ft_strrchr(file_name, '.');
	if (!file_name)
		file_name = ".be";
	if (ft_strncmp(file_name, ".ber", 5))
	{
		ft_printf("Error\nInvalid map name\n");
		return (0);
	}
	return (1);
}

int	walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map-> width)
		{
			if (map->design[y][0] != '1')
				return (0);
			if (map->design[y][map->width - 1] != '1')
				return (0);
			if (map->design[0][x] != '1')
				return (0);
			if (map->design[map->height - 1][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_characters(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->design[y][x] != '0' && map->design[y][x] != '1'
			&& map->design[y][x] != 'P' && map->design[y][x] != 'C'
			&& map->design[y][x] != 'E')
			{
				ft_printf("Error\n Invalid characters!\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
