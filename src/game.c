/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:54:11 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/13 09:54:11 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../inc/game.h"
#include "../inc/screen.h"

void	*delete_game(t_game *game)
{
	if (!game)
		return (NULL);
	if (game->map)
		delete_map(game->map);
	if (game->player)
		delete_player(game->player);
	free(game);
	return (NULL);
}

t_game	*get_game(char *filename)
{
	t_game	*game;

	if (!filename)
		return (NULL);
	game = (t_game *) malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = get_map(filename);
	if (!(game->map))
	{
		write(1, "Error. Error reading the map\n", 30);
		return (free(game), NULL);
	}
	game->player = get_player(game->map);
	if (!game->player)
		return (delete_game(game));
	game->screen = get_screen(game->map->columns, game->map->rows);
	if (!game->screen)
		return (delete_game(game));
	game->screen->map = game->map->map;
	game->screen->game = game;
	game->steps = 0;
	return (game);
}

void	print_steps(t_game *game)
{
	write(1, "Steps: ", 7);
	ft_putnbr_fd(game->steps, 1);
	write(1, "\n", 1);
}

void	print_end(t_game *game)
{
	write(1, "\n################################################\n", 50);
	write(1, "#                                              #\n", 49);
	write(1, "#     ______    ______    _    _    ______     #\n", 49);
	write(1, "#    |  ____|  |  __  |  | \\  / |  |   ___|    #\n", 49);
	write(1, "#    | | ___   | |  | |  |  \\/  |  |  |_       #\n", 49);
	write(1, "#    | ||_  |  | |__| |  | |\\/| |  |   _|      #\n", 49);
	write(1, "#    | |__| |  |  __  |  | |  | |  |  |___     #\n", 49);
	write(1, "#    |______|  |_|  |_|  |_|  |_|  |______|    #\n", 49);
	write(1, "#                                              #\n", 49);
	write(1, "#     ______    _    _    ______    ______     #\n", 49);
	write(1, "#    |  __  |  | |  | |  |   ___|  |  __  |    #\n", 49);
	write(1, "#    | |  | |  | |  | |  |  |_     | |__| |    #\n", 49);
	write(1, "#    | |  | |  \\  \\/  /  |   _|    |   ___|    #\n", 49);
	write(1, "#    | |__| |   \\    /   |  |___   |  |\\ \\     #\n", 49);
	write(1, "#    |______|    \\__/    |______|  |__| \\_|    #\n", 49);
	write(1, "#                                              #\n", 49);
	write(1, "################################################\n", 49);
	write(1, "\n\t\t   ", 6);
	print_steps(game);
	write(1, "\n", 1);
}
