/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:34:02 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/17 10:26:24 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/structs.h"
#include "../inc/screen.h"

#define PY_ANIM 2000

static void	print_player(t_data *screen, int frame)
{
	if (screen->ply_priority == 0)
		screen->player_sprite = screen->sprites->player1;
	else if (screen->ply_priority == 1 && screen->ply_frame >= PY_ANIM)
	{
		if (!frame)
			screen->player_sprite = screen->sprites->player1;
		else
			screen->player_sprite = screen->sprites->player2;
		screen->ply_priority = 0;
		screen->ply_frame = 0;
	}
	else
		screen->ply_frame++;
}

void	change_sprites(t_data *screen, int frame)
{
	t_images	*sprites;

	sprites = screen->sprites;
	print_player(screen, frame);
	if (frame == 0)
	{
		screen->wall_sprite = sprites->wall1;
		screen->floor_sprite = sprites->back1;
		screen->coll_sprite = sprites->coll1;
		screen->enemy_sprite = sprites->enemy1;
		return ;
	}
	screen->wall_sprite = sprites->wall2;
	screen->floor_sprite = sprites->back2;
	screen->coll_sprite = sprites->coll2;
	screen->enemy_sprite = sprites->enemy2;
}
