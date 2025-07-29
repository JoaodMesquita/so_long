/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:22:36 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/29 15:43:05 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	floor_img(t_map *map, int x, int y)
{
	char	*floor_path;

	floor_path = "sprites/floor.xpm";
	map->img_floor = mlx_xpm_file_to_image(map->mlx,
			floor_path, &map->img_width, &map->img_height);
	if (!map->img_floor)
		return (-1);	
	mlx_put_image_to_window(map->mlx,
		map->mlx_win, map->img_floor, x * map->img_width, y * map->img_height);
	return (0);
}

int	player_img(t_map *map, int x, int y)
{
	char	*player_path;

	player_path = "sprites/samurai_jack.xpm";
	map->img_player = mlx_xpm_file_to_image(map->mlx,
			player_path, &map->img_width, &map->img_height);
	if (!map->img_player)
		return (-1);
	mlx_put_image_to_window(map->mlx,
		map->mlx_win, map->img_player, x * map->img_width, y * map->img_height);
	return (0);
}

int	exit_img(t_map *map, int x, int y)
{
	char	*exit_path;

	exit_path = "sprites/door.xpm";
	map->img_exit = mlx_xpm_file_to_image(map->mlx,
			exit_path, &map->img_width, &map->img_height);
	if (!map->img_exit)
		return (-1);
	mlx_put_image_to_window(map->mlx,
		map->mlx_win, map->img_exit, x * map->img_width, y * map->img_height);
	return (0);
}

int	collectible_img(t_map *map, int x, int y)
{
	char	*collectible_path;

	collectible_path = "sprites/collectible.xpm";
	map->img_collectible = mlx_xpm_file_to_image(map->mlx,
			collectible_path, &map->img_width, &map->img_height);
	if (!map->img_collectible)
		return (-1);
	mlx_put_image_to_window(map->mlx,
		map->mlx_win, map->img_collectible, x * map->img_width, y * map->img_height);
	return (0);
}

int	wall_img(t_map *map, int x, int y)
{
	char	*wall_path;

	wall_path = "sprites/wall.xpm";
	map->img_wall = mlx_xpm_file_to_image(map->mlx,
			wall_path, &map->img_width, &map->img_height);
	if (!map->img_wall)
		return (-1);
	mlx_put_image_to_window(map->mlx,
		map->mlx_win, map->img_wall, x * map->img_width, y * map->img_height);
	return (0);
}
