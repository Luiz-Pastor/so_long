/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:00:11 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/14 09:47:18 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../mlx/mlx.h"
#include "../inc/structs.h"
#include "../inc/game.h"
#include "../inc/screen.h"

void	leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	atexit(leaks);
	if (argc != 2)
		return (printf("Usage: %s <name_map>.ber\n", argv[0]));
	game = get_game(argv[1]);
	if (!game)
		return (1);
	mlx_loop_hook(game->screen->mlx, render, game->screen);
	mlx_loop(game->screen->mlx);
	return (0);
}
