/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:34:02 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/16 12:08:40 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/structs.h"
#include "../inc/screen.h"

void	change_sprites(t_data *screen, int frame)
{
	t_images	*sprites;

	sprites = screen->sprites;
	if (frame == 0)
	{
		screen->player_sprite = sprites->player1;
		screen->wall_sprite = sprites->wall1;
		screen->floor_sprite = sprites->back1;
		screen->coll_sprite = sprites->coll1;
		return ;
	}
	screen->player_sprite = sprites->player2;
	screen->wall_sprite = sprites->wall2;
	screen->floor_sprite = sprites->back2;
	screen->coll_sprite = sprites->coll2;
}
