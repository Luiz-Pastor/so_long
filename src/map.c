/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:49:11 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/14 10:00:51 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

static int	get_rows(char *filename)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		rows++;
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

static int	get_columns(char **map)
{
	int	column;
	int	i;
	int	j;

	i = 0;
	column = -1;
	if (!map)
		return (-1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (column == -1)
			column = j;
		if (column != j)
			return (-1);
		i++;
	}
	return (column);
}

static char	**read_map(char *filename)
{
	int		fd;
	int		rows;
	int		i;
	char	**map;

	i = 0;
	rows = get_rows(filename);
	if (rows == -1)
		return (NULL);
	map = (char **) malloc((rows + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	while (i < rows)
	{
		map[i++] = get_next_line(fd);
		if (i != rows)
			map[i - 1][ft_strlen(map[i - 1]) - 1] = '\0';
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	count_collectable(t_map *map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
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

int	set_points(t_map *map)
{
	int	y;
	int	x;
	int	start;
	int	end;

	start = 0;
	end = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				if (start)
					return (1);
				map->start.x = x;
				map->start.y = y;
				start = 1;
			}
			else if (map->map[y][x] == 'E')
			{
				if (end)
					return (1);
				map->out.x = x;
				map->out.y = y;
				end = 1;
			}
			x++;
		}
		y++;
	}
	return (0);
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

t_map	*get_map(char *filename)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->rows = get_rows(filename);
	map->map = read_map(filename);
	map->columns = get_columns(map->map);
	map->collectable = count_collectable(map);
	set_points(map);
	return (check_map(map));
}

void	*delete_map(t_map *map)
{
	int	index;

	index = 0;
	if (!map)
		return (NULL);
	print_map_info(map);
	if (map->map)
	{
		while (map->map[index])
			free(map->map[index++]);
		free(map->map);
	}
	free(map);
	return (NULL);
}
/*
void	print_map_info(t_map *map)
{
	int	y = 0;
	
	if (!map)
		return ;
	printf("> Map:\n");
	while (map->map[y])
		printf("\t%s\n", map->map[y++]);
	printf("> Filas: %d\n", map->rows);
	printf("> Columnas: %d\n", map->columns);
	printf("> Coleccionables: %d\n", map->collectable);
	printf("> Start point: (%d, %d)\n", map->start.x, map->start.y);
	printf("> End point: (%d, %d)\n", map->out.x, map->out.y);
	printf("> Hay camino posible: ");
	find_path(map) != 0 ? printf("Si\n") : printf("No\n");
	printf("> Mapa encerrado: ");
	map_locked(map) == 1 ? printf("Si\n") : printf("No\n");
}*/
