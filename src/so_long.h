/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:36:51 by joapedro          #+#    #+#             */
/*   Updated: 2025/08/11 10:16:37 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 64

# include "../mlx-linux/mlx.h"
# include <X11/keysym.h>
# include "../libft/libft.h"
# include <X11/X.h>

typedef struct s_map
{
	int		width;
	int		height;
	int		collectable;
	int		player;
	int		exit;
	int		floor;
	int		start_x;
	int		start_y;
	int		moves;
	int		*img_player;
	int		*img_collectible;
	int		*img_wall;
	int		*img_exit;
	int		*img_floor;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;
	char	**design;
}			t_map;

int		handle_input(int keysym, t_map *map);
int		arrow_handler(int keysym, t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);
void	move_left(t_map *map);
int		check_map(int ac, char **av, t_map *map);
int		check_args(int ac);
int		check_map_name(char *file_name);
int		check_min_characters(t_map *map);
int		check_characters(t_map *map);
void	initialize(t_map *map);
void	map_height(char *file_name, t_map *map);
void	map_read(char *file_name, t_map *map);
int		walls(t_map *map);
int		map_shape(t_map *map);
void	str_trim(char *str);
int		valid_exit(t_map *map, char *file_name);
void	player_position(t_map *map);
void	flood_fill(t_map *map, int x, int y);
void	free_map(t_map *map);
void	map_render(t_map *map);
int		floor_img(t_map *map, int x, int y);
int		player_img(t_map *map, int x, int y);
int		exit_img(t_map *map, int x, int y);
int		wall_img(t_map *map, int x, int y);
int		collectible_img(t_map *map, int x, int y);
void	render_tile(char tile, t_map *map, int x, int y);
int		ft_quit(t_map *map);
void	*ft_memset(void *dest, int c, size_t n);

#endif