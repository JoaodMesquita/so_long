#include "../so_long.h"

int check_map(int ac, char **av)
{
	t_map map;

	if (check_args(ac))
		return (0);
    if (check_map_name(av[1]))
		return (0);
	initialize(&map);
	map_height(av[1], &map);
	map_read(av[1], &map);
	if (check_min_characters(&map))
		return (0);
	if (map_shape(&map))
		return (0);
	return (1);
}