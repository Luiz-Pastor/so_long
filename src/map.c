/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:49:11 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/17 10:13:32 by lpastor-         ###   ########.fr       */
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
	if (fd < 0)
		return (NULL);
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
	return (check_map(map));
}

void	*delete_map(t_map *map)
{
	int	index;

	index = 0;
	if (!map)
		return (NULL);
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
