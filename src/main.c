/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:08:07 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/25 10:48:58 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_quit(t_game *game)
{
	(void)game;
	exit(1);
}
int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;
	t_game game;

	if (!check_map(ac, av, &map))
	{
		free_map(&map);
		return (1);
	}

	game.mlx = mlx_init();
	game.map = &map;
	if (!game.mlx)
		return (0);

	game.mlx_win = mlx_new_window(game.mlx, map.width * TILE_SIZE, map.height * TILE_SIZE, "so_long");
	if(!game.mlx_win)
		return (0);

	map_render(&map, &data, &game);

	//mlx_key_hook(game.mlx_win, &player_moves, &game);
	mlx_hook(game.mlx_win, KeyPress, KeyPressMask, &handle_input, &game);
	mlx_hook(game.mlx_win, DestroyNotify, 0, &ft_quit, &game);
	mlx_loop(game.mlx);
	return (0);
}

