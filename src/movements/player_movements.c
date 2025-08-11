/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:42:41 by joapedro          #+#    #+#             */
/*   Updated: 2025/08/11 10:15:02 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	winning_message(t_map *map)
{
	map->moves++;
	ft_printf("You did: %d moves\n", map->moves);
	ft_printf("You are an inspiration to all of us\n");
}

void	move_up(t_map *map)
{
	int	y;
	int	x;

	y = map->start_y;
	x = map->start_x;
	if (map->design[y - 1][x] == '1')
		return ;
	if (map->design[y - 1][x] == 'C')
	{
		map->collectable--;
		map->design[y - 1][x] = '0';
	}
	if (map->design[y - 1][x] == 'E' && map->collectable > 0)
		return ;
	if (map->design[y - 1][x] == 'E' && map->collectable == 0)
	{
		winning_message(map);
		ft_quit(map);
	}
	map->design[y][x] = '0';
	map->design[y - 1][x] = 'P';
	map->start_y = y - 1;
	map->moves++;
	ft_printf("You did: %d moves\n", map->moves);
	map_render(map);
}

void	move_right(t_map *map)
{
	int	y;
	int	x;

	y = map->start_y;
	x = map->start_x;
	if (map->design[y][x + 1] == '1')
		return ;
	if (map->design[y][x + 1] == 'C')
	{
		map->collectable--;
		map->design[y][x + 1] = '0';
	}
	if (map->design[y][x + 1] == 'E' && map->collectable > 0)
		return ;
	if (map->design[y][x + 1] == 'E' && map->collectable == 0)
	{
		winning_message(map);
		ft_quit(map);
	}
	map->design[y][x] = '0';
	map->design[y][x + 1] = 'P';
	map->start_x = x + 1;
	map->moves++;
	ft_printf("You did: %d moves\n", map->moves);
	map_render(map);
}

void	move_down(t_map *map)
{
	int	y;
	int	x;

	y = map->start_y;
	x = map->start_x;
	if (map->design[y + 1][x] == '1')
		return ;
	if (map->design[y + 1][x] == 'C')
	{
		map->collectable--;
		map->design[y + 1][x] = '0';
	}
	if (map->design[y + 1][x] == 'E' && map->collectable > 0)
		return ;
	if (map->design[y + 1][x] == 'E' && map->collectable == 0)
	{
		winning_message(map);
		ft_quit(map);
	}
	map->design[y][x] = '0';
	map->design[y + 1][x] = 'P';
	map->start_y = y + 1;
	map->moves++;
	ft_printf("You did: %d moves\n", map->moves);
	map_render(map);
}

void	move_left(t_map *map)
{
	int	y;
	int	x;

	y = map->start_y;
	x = map->start_x;
	if (map->design[y][x - 1] == '1')
		return ;
	if (map->design[y][x - 1] == 'C')
	{
		map->collectable--;
		map->design[y][x - 1] = '0';
	}
	if (map->design[y][x - 1] == 'E' && map->collectable > 0)
		return ;
	if (map->design[y][x - 1] == 'E' && map->collectable == 0)
	{
		winning_message(map);
		ft_quit(map);
	}
	map->design[y][x] = '0';
	map->design[y][x - 1] = 'P';
	map->start_x = x - 1;
	map->moves++;
	ft_printf("You did: %d moves\n", map->moves);
	map_render(map);
}
