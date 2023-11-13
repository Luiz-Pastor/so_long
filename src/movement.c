/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:58:31 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/13 08:58:31 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

// TODO
void	move_right(t_game *game)
{
	// Si se sale del mapa, nada
	if (game->player->coords.x + 1 == game->map->columns)
		return ;
	
	// Si se estampa contra muro, nada
	if (game->map->map[game->player->coords.y][game->player->coords.x + 1] == '1')
		return ;
	
	// Si va a la puerta sin todos los coleccionables, nada
	if (game->map->map[game->player->coords.y][game->player->coords.x + 1] == 'E' && \
		game->player->collec != game->map->collectable)
		return ;
	
	// Si va a la puerta con todos los coleccionables, ALGO
	if (game->map->map[game->player->coords.y][game->player->coords.x + 1] == 'E' && \
		game->player->collec == game->map->collectable)
		return ;

	game->map->map[game->player->coords.y][game->player->coords.x] = '0';
	if (game->map->map[game->player->coords.y][game->player->coords.x + 1] == 'C')
		(game->player->collec)++;
	game->map->map[game->player->coords.y][game->player->coords.x + 1] = 'P';
	(game->steps)++;
}

void	move_down(t_game *game)
{

}

void	move_left(t_game *game)
{

}

void	move_right(t_game *game)
{

}