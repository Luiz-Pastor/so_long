/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:00:11 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/02 13:08:33 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../inc/structs.h"
#include "../libft/libft.h"

int	get_rows(char *filename)
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

char **read_map(char *filename)
{
	int		fd;
	int		rows;
	int		i;
	char	**map;
	
	rows = get_rows(filename);
	if (rows == -1)
		return (NULL);
	map = (char **) malloc((rows + 1) * sizeof(char *));
	if (!map)
		return (NULL);

	i = 0;
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

int	get_columns(char **map)
{
	int	column;
	int	i;
	int	j;

	i = 0;
	column = -1;
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
void	*delete_map(t_map **map)
{
	int	index;
	
	index = 0;
	if (!map || !(*map))
		return (NULL);
	if ((*map)->map)
	{
		while ((*map)->map[index])
			free((*map)->map[index++]);
		free((*map)->map);
	}
	free((*map));
	*map = NULL;
	return (NULL);
}

t_map	*get_map(char *filename)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->rows = get_rows(filename); 
	if (map->rows == -1)
		return (delete_map(&map));
	map->map = read_map(filename);
	if (!(map->map))
		return (delete_map(&map));
	map->columns = get_columns(map->map);
	if (map->columns == -1)
		return (delete_map(&map));
	return (map);
}

void leaks()
{
	system("leaks -q so_long");
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	atexit(leaks);
	if (argc != 2)
		return (printf("Usage: %s <name_map>.ber\n", argv[0]));	

	map = get_map(argv[1]);
	if (!map)
		return (printf("Error reading the map\n"));

	int index = 0;
	while (map->map[index])
		printf("%s\n", map->map[index++]);

	delete_map(&map);
	return (0);
}
