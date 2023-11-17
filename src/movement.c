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

static void	set_sprite_pos(t_game *game, int pos)
{
	t_images	*sprites;

	sprites = game->screen->sprites;
	if (pos == 0)
		game->screen->player_sprite = sprites->player_up;
	else if (pos == 1)
		game->screen->player_sprite = sprites->player_right;
	else if (pos == 2)
		game->screen->player_sprite = sprites->player_left;
	else
		game->screen->player_sprite = sprites->player_down;
	game->screen->ply_priority = 1;
	game->screen->ply_frame = 0;
}

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
	if ((game->map->map[y][x + 1] == 'E' && \
		game->player->collec == game->map->collectable) || \
		game->map->map[y][x + 1] == 'M')
		end_game(game->screen);
	game->map->map[y][x] = '0';
	if (game->map->map[y][x + 1] == 'C')
		(game->player->collec)++;
	game->map->map[y][x + 1] = 'P';
	(game->steps)++;
	(game->player->coords.x++);
	print_steps(game);
	set_sprite_pos(game, 1);
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
	if ((game->map->map[y][x - 1] == 'E' && \
		game->player->collec == game->map->collectable) || \
		game->map->map[y][x - 1] == 'M')
		end_game(game->screen);
	game->map->map[y][x] = '0';
	if (game->map->map[y][x - 1] == 'C')
		(game->player->collec)++;
	game->map->map[y][x - 1] = 'P';
	(game->steps)++;
	(game->player->coords.x--);
	print_steps(game);
	set_sprite_pos(game, 2);
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
	if ((game->map->map[y + 1][x] == 'E' && \
		game->player->collec == game->map->collectable) || \
		game->map->map[y + 1][x] == 'M')
		end_game(game->screen);
	game->map->map[y][x] = '0';
	if (game->map->map[y + 1][x] == 'C')
		(game->player->collec)++;
	game->map->map[y + 1][x] = 'P';
	(game->steps)++;
	(game->player->coords.y++);
	print_steps(game);
	set_sprite_pos(game, 3);
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
	if ((game->map->map[y - 1][x] == 'E' && \
		game->player->collec == game->map->collectable) || \
		game->map->map[y - 1][x] == 'M')
		end_game(game->screen);
	game->map->map[y][x] = '0';
	if (game->map->map[y - 1][x] == 'C')
		(game->player->collec)++;
	game->map->map[y - 1][x] = 'P';
	(game->steps)++;
	(game->player->coords.y--);
	print_steps(game);
	set_sprite_pos(game, 0);
}
