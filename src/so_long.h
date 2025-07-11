/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:36:51 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/11 15:46:40 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

# include "../mlx-linux/mlx.h"
#include <X11/keysym.h>
#include "../lib/lib.h"

typedef struct s_map
{
	int	width;
	int	height;
	int	collectable;
	int	player;
	int	exit;
	int	floor;
	int	start_x;
	int	start_y;
	char	**design;
}			t_map;


typedef struct s_player
{
	int	*img;
	int	img_width;
	int	img_height;
	int	x;
	int	y;
}			t_player;

typedef struct s_data
{
	int		x;
	int 	y;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int	img_width;
	int	img_height;
}			t_data;

typedef struct s_game
{
	t_player *player;
	t_data *data;
}			t_game;

int		handle_input(int keysym, t_data *data);
int		player_moves(int keysym, t_game *game);
int		check_map(int ac, char **av);
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

#endif