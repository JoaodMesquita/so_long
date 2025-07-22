#include "so_long.h"

int	floor_img(t_data *data, t_game *game, int x, int y)
{
	char	*floor_path;
	floor_path = "sprites/floor.xpm";
	data->img = mlx_xpm_file_to_image(game->mlx, floor_path, &data->img_width, &data->img_height);
	if (!data->img)
		return (-1);
	mlx_put_image_to_window(game->mlx, game->mlx_win, data->img, x * data->img_width, y * data->img_height);
	
	return (0);
}

int	player_img(t_data *data, t_game *game, int x, int y)
{
	char	*player_path;

	player_path = "sprites/samurai_jack.xpm";
	data->img = mlx_xpm_file_to_image(game->mlx, player_path, &data->img_width, &data->img_height);
	if (!data->img)
		return (-1);
	mlx_put_image_to_window(game->mlx, game->mlx_win, data->img, x * data->img_width, y * data->img_height);

	return (0);
}

int exit_img (t_data *data, t_game *game, int x, int y)
{
	char	*exit_path;

	exit_path = "sprites/door.xpm";
	data->img = mlx_xpm_file_to_image(game->mlx, exit_path, &data->img_width, &data->img_height);
	if (!data->img)
		return (-1);
	mlx_put_image_to_window(game->mlx, game->mlx_win, data->img, x * data->img_width, y * data->img_height);

	return (0);
}

int collectible_img (t_data *data, t_game *game, int x, int y) 
{
	char	*collectible_path;

	collectible_path = "sprites/collectible.xpm";
	data->img = mlx_xpm_file_to_image(game->mlx, collectible_path, &data->img_width, &data->img_height);
	if (!data->img)
		return (-1);
	mlx_put_image_to_window(game->mlx, game->mlx_win, data->img, x * data->img_width, y * data->img_height);

	return (0);
}
int wall_img (t_data *data, t_game *game, int x, int y)
{
	char	*wall_path;

	wall_path = "sprites/wall.xpm";
	data->img = mlx_xpm_file_to_image(game->mlx, wall_path, &data->img_width, &data->img_height);
	if (!data->img)
		return (-1);
	mlx_put_image_to_window(game->mlx, game->mlx_win, data->img, x * data->img_width, y * data->img_height);

	return (0);
}

