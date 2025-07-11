/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:29:31 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/11 15:58:49 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->collectable = 0;
	map->design = NULL;
	map->player = 0;
	map->floor = 0;
	map->exit = 0;
	map->start_x = 0;
	map->start_y = 0;
}

void str_trim(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
			str[i] = '\0';
		i++;
	}
}

void free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map->design)
		return ;
	while (i < map->height)
	{
		if (map->design[i])
			free(map->design[i]);
		i++;
	}
	free(map->design);
}