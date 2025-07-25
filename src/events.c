/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:18:28 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/25 10:29:20 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_map *map, t_data *data, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(1);
	}
	else 
		key_arrows(keysym, map, data, game);
	return (0);
}
int	key_arrows(int keysym, t_map *map, t_data *data, t_game *game)
{
	if (keysym == XK_Up)
	{
		move_up(map, data, game);
	}
	if (keysym == XK_Right)
	{
		move_right(map, data, game);
	}
	if (keysym == XK_Down)
	{
		move_down(map, data, game);
	}
	if (keysym == XK_Left)
	{
		move_left(map, data, game);
	}
	return (0);	
}