/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:47:31 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/14 09:47:31 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

static int	find_path_rec(char **map, int x, int y, t_map *data)
{
	int	count;
	int	x_max;
	int	y_max;

	x_max = data->columns;
	y_max = data->rows;
	count = 0;
	if (map[y][x] == 'E')
		return (1);
	else
		map[y][x] = '1';
	if (x - 1 >= 0 && map[y][x - 1] != '1' && map[y][x - 1] != 'M')
		count += find_path_rec(map, x - 1, y, data);
	if (x + 1 < x_max && map[y][x + 1] != '1' && map[y][x + 1] != 'M')
		count += find_path_rec(map, x + 1, y, data);
	if (y - 1 >= 0 && map[y - 1][x] != '1' && map[y - 1][x] != 'M')
		count += find_path_rec(map, x, y - 1, data);
	if (y + 1 < y_max && map[y + 1][x] != '1' && map[y + 1][x] != 'M')
		count += find_path_rec(map, x, y + 1, data);
	return (count);
}

static void	check_collec(int *res, char **map)
{
	int	x;
	int	y;

	y = 0;
	if (*res == 0)
		return ;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				*res = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	find_path(t_map *map)
{
	char	**map_copy;
	int		y;	
	int		res;

	y = 0;
	map_copy = (char **) malloc((map->rows + 1) * sizeof(char *));
	if (!map_copy)
		return (0);
	while (map->map[y])
	{
		map_copy[y] = ft_strdup(map->map[y]);
		y++;
	}
	map_copy[y] = NULL;
	res = find_path_rec(map_copy, map->start.x, map->start.y, map);
	check_collec(&res, map_copy);
	y = 0;
	while (map_copy[y])
		free(map_copy[y++]);
	free(map_copy);
	return (res);
}

int	map_locked(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if ((y == 0 || y == map->rows - 1) && map->map[y][x] != '1')
				return (0);
			if (x == 0 && map->map[y][x] != '1')
				return (0);
			x++;
		}
		if (map->map[y][x - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
