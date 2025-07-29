/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:18:28 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/29 15:41:33 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit(t_map *map)
{
	if (map->img_player)
		mlx_destroy_image(map->mlx, map->img_player);
	if (map->img_wall)
		mlx_destroy_image(map->mlx, map->img_wall);
	if (map->img_collectible)
		mlx_destroy_image(map->mlx, map->img_collectible);
	if (map->img_floor)
		mlx_destroy_image(map->mlx, map->img_floor);
	if (map->img_exit)
		mlx_destroy_image(map->mlx, map->img_exit);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if(map)
		free_map(map);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	exit(0);
}

int	handle_input(int keysym, t_map *map)
{
	if (keysym == XK_Escape)
	{
		ft_quit(map);
	}
	else
	{
		arrow_handler(keysym, map);
	}
	return (0);
}

int	arrow_handler(int keysym, t_map *map)
{
	if (keysym == XK_Up)
	{
		move_up(map);
	}
	if (keysym == XK_Down)		
	{
		move_down(map);
	}
	if (keysym == XK_Left)
	{
		move_left(map);
	}
	if (keysym == XK_Right)
	{
		move_right(map);
	}
	return (0);
}
