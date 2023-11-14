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
		printf("Error reading the map\n");
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
