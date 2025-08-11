/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:08:07 by joapedro          #+#    #+#             */
/*   Updated: 2025/08/11 10:15:15 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	if (!check_map(ac, av, &map))
	{
		free_map(&map);
		return (1);
	}
	map.mlx = mlx_init();
	if (!map.mlx)
		return (0);
	map.mlx_win = mlx_new_window(map.mlx, map.width
			* SIZE, map.height * SIZE, "so_long");
	if (!map.mlx_win)
		return (0);
	if (!map.mlx_win)
		return (0);
	map_render(&map);
	mlx_hook(map.mlx_win, KeyPress, KeyPressMask, &handle_input, &map);
	mlx_hook(map.mlx_win, DestroyNotify, 0, ft_quit, &map);
	mlx_loop(map.mlx);
	return (0);
}
