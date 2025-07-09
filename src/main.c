/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:08:07 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/08 12:00:51 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int	main(int ac, char **av)
{
	char	*player_path = "sprites/samurai_jack.xpm";
	char	*background_path = "sprites/floor.xpm";
	t_data	data;
	t_player player;
	t_game game;

	check_map(ac, av);

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);

	data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Samurai Jack I");
	if(!data.mlx_win)
		return (1);

	data.img = mlx_xpm_file_to_image(data.mlx, background_path, &data.img_width, &data.img_height);
	if(!data.img)
		return (1);

	data.y = 0;
	while (data.y < WIN_HEIGHT)
	{
		data.x = 0;
		while (data.x < WIN_WIDTH)
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, data.x, data.y);
			data.x += data.img_width;
		}
		data.y += data.img_height;
	}

	player.img = mlx_xpm_file_to_image(data.mlx, player_path, &player.img_width, &player.img_height);
	if(!player.img)
		return(1);
	

	player.x = 1;
	player.y = 1;

	mlx_put_image_to_window(data.mlx, data.mlx_win, player.img, player.x, player.y);

	ft_printf("player.x = %d\n", player.x);
	
	game.data = &data;
	game.player = &player;
	/*hooks*/
	mlx_key_hook(data.mlx_win, &player_moves, &game);
	mlx_loop_hook(data.mlx, &handle_input, &data);

	mlx_loop(data.mlx);
	return (0);
}

