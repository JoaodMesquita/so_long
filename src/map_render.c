#include "so_long.h"

void map_render(t_map *map, t_data *data, t_game *game)
{
	int y;
	int x;

	y = 0;
	while(y < map->height)
	{
		x = 0;
		while(x < map->width)
		{
			render_tile(map->design[y][x], data, game, x, y);
			x++;
		}
		y++;
	}
}

void render_tile(char tile, t_data *data , t_game *game, int x, int y)
{
	if (tile == '1')
		wall_img(data, game, x, y);
	if (tile == '0')
		floor_img(data, game, x, y);
	if (tile == 'P')
		player_img(data, game, x, y);
	if (tile == 'C')
		collectible_img(data, game, x, y);
	if (tile == 'E')
		exit_img(data, game, x, y);
}