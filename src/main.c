/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:08:07 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/22 15:42:38 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;
	t_game game;

	check_map(ac, av, &map);

	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);

	game.mlx_win = mlx_new_window(game.mlx, map.width * TILE_SIZE, map.height * TILE_SIZE, "so_long");
	if(!game.mlx_win)
		return (0);

	map_render(&map, &data, &game);

	mlx_key_hook(game.mlx_win, &player_moves, &game);
	//mlx_loop_hook(game.mlx, &handle_input, &data);

	mlx_loop(game.mlx);
	return (0);
}

