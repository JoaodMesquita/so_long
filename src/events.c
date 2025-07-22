/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:18:28 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/22 15:44:00 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_moves(int keysym, t_game *game)
{
	if (keysym == XK_Right)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->mlx_win, game->data->img, game->player->x, game->player->y);
		game->player->x += game->player->img_width;
		mlx_put_image_to_window(game->data->mlx, game->data->mlx_win, game->player->img, game->player->x, game->player->y);

	}
	if (keysym == XK_Up)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->mlx_win, game->data->img, game->player->x, game->player->y);
		game->player->y -= game->player->img_height;
		mlx_put_image_to_window(game->data->mlx, game->data->mlx_win, game->player->img, game->player->x, game->player->y);
	}
	if (keysym == XK_Down)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->mlx_win, game->data->img, game->player->x, game->player->y);
		game->player->y += game->player->img_height;
		mlx_put_image_to_window(game->data->mlx, game->data->mlx_win, game->player->img, game->player->x, game->player->y);
	}
	if (keysym == XK_Left)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->mlx_win, game->data->img, game->player->x, game->player->y);
		game->player->x -= game->player->img_width;
		mlx_put_image_to_window(game->data->mlx, game->data->mlx_win, game->player->img, game->player->x, game->player->y);
	}
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->data->mlx, game->data->mlx_win);
	}
	return (0);	
}
int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
	}
	return (0);
} */


