/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:36:51 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/25 10:28:00 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define TILE_SIZE 64

# include "../mlx-linux/mlx.h"
#include <X11/keysym.h>
#include "../lib/lib.h"
# include <X11/X.h>
typedef struct s_map
{
	int	width;
	int	height;
	int	collectable;
	int	player;
	int	exit;
	int	floor;
	int	start_x; //flood fill
	int	start_y; // flood fill
	char	**design;
}			t_map;

typedef struct s_data
{
	int	*img;
	int	img_width;
	int	img_height;
	int	x;
	int	y;
}			t_data;  

typedef struct s_game
{
	void *mlx;
	void *mlx_win;
	t_map	*map;
}			t_game;

typedef struct s_player
{
	int		x;
	int		y;
}			t_player;

int		handle_input(int keysym, t_map *map, t_data *data, t_game *game);
int		key_arrows(int keysym, t_map *map, t_data *data, t_game *game);
void	move_up(t_map *map, t_data *data, t_game *game);
void	move_right(t_map *map, t_data *data, t_game *game);
void	move_down(t_map *map, t_data *data, t_game *game);
void	move_left(t_map *map, t_data *data, t_game *game);
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
void	map_render(t_map *map, t_data *data, t_game *game);
int		floor_img(t_data *data, t_game *game, int x, int y);
int		player_img(t_data *data, t_game *game, int x, int y);
int		exit_img (t_data *data, t_game *game, int x, int y);
int		wall_img (t_data *data, t_game *game, int x, int y);
int		collectible_img (t_data *data, t_game *game, int x, int y);
void	render_tile(char tile, t_data *data , t_game *game, int x, int y);

#endif