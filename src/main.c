/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:00:11 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/03 09:33:37 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/structs.h"
#include "../inc/map.h"


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

	print_map_info(map);

	delete_map(&map);
	return (0);
}
