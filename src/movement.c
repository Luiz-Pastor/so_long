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
#include "../inc/game.h"
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
	print_steps(game);
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
	print_steps(game);
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player->coords.x;
	y = game->player->coords.y;
	if (y + 1 == game->map->columns)
		return ;
	if (game->map->map[y + 1][x] == '1')
		return ;
	if (game->map->map[y + 1][x] == 'E' && \
		game->player->collec != game->map->collectable)
		return ;
	if (game->map->map[y + 1][x] == 'E' && \
		game->player->collec == game->map->collectable)
		end_game(game->screen);
	game->map->map[y][x] = '0';
	if (game->map->map[y + 1][x] == 'C')
		(game->player->collec)++;
	game->map->map[y + 1][x] = 'P';
	(game->steps)++;
	(game->player->coords.y++);
	print_steps(game);
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player->coords.x;
	y = game->player->coords.y;
	if (y - 1 == game->map->columns)
		return ;
	if (game->map->map[y - 1][x] == '1')
		return ;
	if (game->map->map[y - 1][x] == 'E' && \
		game->player->collec != game->map->collectable)
		return ;
	if (game->map->map[y - 1][x] == 'E' && \
		game->player->collec == game->map->collectable)
		end_game(game->screen);
	game->map->map[y][x] = '0';
	if (game->map->map[y - 1][x] == 'C')
		(game->player->collec)++;
	game->map->map[y - 1][x] = 'P';
	(game->steps)++;
	(game->player->coords.y--);
	print_steps(game);
}
