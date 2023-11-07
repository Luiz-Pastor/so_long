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
#include "../inc/game.h"


void leaks()
{
	system("leaks -q so_long");
}

int	main(int argc, char *argv[])
{
	atexit(leaks);

	/*t_map	*map;
	t_player	*player;*/
	t_game	*game;


	if (argc != 2)
		return (printf("Usage: %s <name_map>.ber\n", argv[0]));	

	game = get_game(argv[1]);
	if (!game)
		return (1);

	/* print_map_info(game->map); */

	delete_game(game);
	return (0);
}
