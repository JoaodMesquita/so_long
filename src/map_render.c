/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:22:28 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/29 10:31:51 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_render(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			render_tile(map->design[y][x], map, x, y);
			x++;
		}
		y++;
	}
}

void	render_tile(char tile, t_map *map, int x, int y)
{
	if (tile == '1')
		wall_img(map, x, y);
	if (tile == '0')
		floor_img(map, x, y);
	if (tile == 'P')
		player_img(map, x, y);
	if (tile == 'C')
		collectible_img(map, x, y);
	if (tile == 'E')
		exit_img(map, x, y);
}
