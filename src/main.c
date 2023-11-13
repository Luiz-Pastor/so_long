/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:00:11 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/13 11:42:05 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../mlx/mlx.h"
#include <stdio.h>
#include "../inc/structs.h"
#include "../inc/game.h"
#include "../inc/screen.h"


void leaks()
{
	system("leaks -q so_long");
}

int	main(int argc, char *argv[])
{
	atexit(leaks);

	t_game	*game;
	t_data	*screen;

	if (argc != 2)
		return (printf("Usage: %s <name_map>.ber\n", argv[0]));	

	game = get_game(argv[1]);
	if (!game)
		return (1);

	screen = get_screen(game);
	if (!screen)
		return (1);

	mlx_loop_hook(screen->mlx, render, screen);
	mlx_loop(screen->mlx);
	return (0);
}
