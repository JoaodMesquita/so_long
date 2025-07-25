#include "../so_long.h"

// if any arrow is pressed, the player must move toward the arrow is pointing;
// if key pressed and there is a wall in front, player cant move (collision);
// if key pressed and there is a collectible, img of collectible must be replaced by floor, and map->collectable must --;
// if there is an exit, player img gets destroyed, message of winning shows up.... 

void move_up(t_map *map, t_data *data, t_game *game)
{
	int y;
	int x;

	y = map->start_y;
	x = map->start_x;

	if (map->design[y - 1][x] == '1')
		return ;
	if (map->design[y - 1][x] == 'C')
	{
		map->collectable--;
		map->design[y - 1][x] = '0';
	}
	if (map->design[y - 1][x] == 'E' && map->collectable == 0)
	{
		ft_printf("You are an inspiration to all of us");
	}
	map_render(map, data, game);
}
void move_right(t_map *map, t_data *data, t_game *game)
{
	int y;
	int x;

	y = map->start_y;
	x = map->start_x;

	if (map->design[y][x - 1] == '1')
		return ;
	if (map->design[y][x - 1] == 'C')
	{
		map->collectable--;
		map->design[y][x - 1] = '0';
	}
	if (map->design[y][x - 1] == 'E' && map->collectable == 0)
	{
		ft_printf("You are an inspiration to all of us");
	}
	map_render(map, data, game);
}

void move_down(t_map *map, t_data *data, t_game *game)
{
	int y;
	int x;
	
	y = map->start_y;
	x = map->start_x;
	
	if (map->design[y + 1][x] == '1')
	return ;
	if (map->design[y + 1][x] == 'C')
	{
		map->collectable--;
		map->design[y + 1][x] = '0';
	}
	if (map->design[y + 1][x] == 'E' && map->collectable == 0)
	{
		ft_printf("You are an inspiration to all of us");
	}
	map_render(map, data, game);
}

void move_left(t_map *map, t_data *data, t_game *game)
{
	int y;
	int x;

	y = map->start_y;
	x = map->start_x;

	if (map->design[y][x + 1] == '1')
		return ;
	if (map->design[y][x + 1] == 'C')
	{
		map->collectable--;
		map->design[y][x + 1] = '0';
	}
	if (map->design[y][x + 1] == 'E' && map->collectable == 0)
	{
		ft_printf("You are an inspiration to all of us");
	}
	map_render(map, data, game);
}