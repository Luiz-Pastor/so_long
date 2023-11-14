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
#include "../inc/screen.h"

// TODO
void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player->coords.x;
	y = game->player->coords.y;
	if (x + 1 == game->map->columns)
		return ;
	if (game->map->map[y][x + 1] == '1')
		return ;
	if (game->map->map[y][x + 1] == 'E' && \
		game->player->collec != game->map->collectable)
		return ;
	if (game->map->map[y][x + 1] == 'E' && \
		game->player->collec == game->map->collectable)
		end_game(game->screen);
	game->map->map[y][x] = '0';
	if (game->map->map[y][x + 1] == 'C')
		(game->player->collec)++;
	game->map->map[y][x + 1] = 'P';
	(game->steps)++;
	(game->player->coords.x++);
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player->coords.x;
	y = game->player->coords.y;
	if (x - 1 == game->map->columns)
		return ;
	if (game->map->map[y][x - 1] == '1')
		return ;
	if (game->map->map[y][x - 1] == 'E' && \
		game->player->collec != game->map->collectable)
		return ;
	if (game->map->map[y][x - 1] == 'E' && \
		game->player->collec == game->map->collectable)
		end_game(game->screen);
	game->map->map[y][x] = '0';
	if (game->map->map[y][x - 1] == 'C')
		(game->player->collec)++;
	game->map->map[y][x - 1] = 'P';
	(game->steps)++;
	(game->player->coords.x--);
}

void	move_down(t_game *game)
{
	if (game->player->coords.y + 1 == game->map->columns)
		return ;
	if (game->map->map[y + 1][x] == '1')
		return ;
	if (game->map->map[game->player->coords.y + 1][game->player->coords.x] == 'E' && \
		game->player->collec != game->map->collectable)
		return ;
	if (game->map->map[game->player->coords.y + 1][game->player->coords.x] == 'E' && \
		game->player->collec == game->map->collectable)
		end_game(game->screen);
	game->map->map[game->player->coords.y][game->player->coords.x] = '0';
	if (game->map->map[game->player->coords.y + 1][game->player->coords.x] == 'C')
		(game->player->collec)++;
	game->map->map[game->player->coords.y + 1][game->player->coords.x] = 'P';
	(game->steps)++;
	(game->player->coords.y++);
}

void	move_up(t_game *game)
{
	if (game->player->coords.y - 1 == game->map->columns)
		return ;
	if (game->map->map[game->player->coords.y - 1][game->player->coords.x] == '1')
		return ;
	if (game->map->map[game->player->coords.y - 1][game->player->coords.x] == 'E' && \
		game->player->collec != game->map->collectable)
		return ;
	if (game->map->map[game->player->coords.y - 1][game->player->coords.x] == 'E' && \
		game->player->collec == game->map->collectable)
		end_game(game->screen);
	game->map->map[game->player->coords.y][game->player->coords.x] = '0';
	if (game->map->map[game->player->coords.y - 1][game->player->coords.x] == 'C')
		(game->player->collec)++;
	game->map->map[game->player->coords.y - 1][game->player->coords.x] = 'P';
	(game->steps)++;
	(game->player->coords.y--);
}
