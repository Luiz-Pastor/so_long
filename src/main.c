/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:00:11 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/15 11:58:21 by lpastor-         ###   ########.fr       */
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

/* ber */
int	check_extension(char *filename)
{
	int	length;

	length = ft_strlen(filename);
	if (filename[length - 1] == 'r' && \
		filename[length - 2] == 'e' && \
		filename[length - 3] == 'b' && \
		filename[length - 4] == '.')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	atexit(leaks);
	if (argc != 2 || !check_extension(argv[1]))
		return (write(1, "Usage: ./so_long <map_file>.ber\n", 33));
	game = get_game(argv[1]);
	if (!game)
		return (1);
	mlx_loop(game->screen->mlx);
	exit(0);
}
