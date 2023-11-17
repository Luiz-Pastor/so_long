/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:42:57 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/17 10:10:14 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int	count_collectable(t_map *map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	if (!(map->map))
		return (-1);
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'C')
				count++;
			if (!ft_strchr(MAP_CH, map->map[y][x]))
				return (-1);
			x++;
		}
		y++;
	}
	return (count);
}

static int	set_x(t_map *map, int *start, int x, int y)
{
	if (*start != 0)
		return (1);
	map->start.x = x;
	map->start.y = y;
	*start = 1;
	return (0);
}

static int	set_y(t_map *map, int *end, int x, int y)
{
	if (*end != 0)
		return (1);
	map->out.x = x;
	map->out.y = y;
	*end = 1;
	return (0);
}

int	set_points(t_map *map)
{
	int	y;
	int	x;
	int	start;
	int	end;

	start = 0;
	end = 0;
	y = -1;
	if (!(map->map))
		return (1);
	while (map->map[++y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
				if (set_x(map, &start, x, y))
					return (1);
			if (map->map[y][x] == 'E')
				if (set_y(map, &end, x, y))
					return (1);
			x++;
		}
	}
	return (0);
}

t_map	*check_map(t_map *map)
{
	if (!map)
		return (NULL);
	if (map->rows < 1 || map->columns < 1 || !(map->map))
		return (delete_map (map));
	if (map->collectable < 1 || set_points(map))
		return (delete_map(map));
	if (!map_locked(map) || !find_path(map))
		return (delete_map(map));
	return (map);
}
