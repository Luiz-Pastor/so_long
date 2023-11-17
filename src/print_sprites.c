/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:59:05 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/17 10:30:53 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/structs.h"
#include "../inc/screen.h"

static void	print_sprites(t_data *screen, int x, int y, void *sprite)
{
	x *= IMAGE_WEIGHT;
	y *= IMAGE_HEIGHT;
	mlx_put_image_to_window(screen->mlx, screen->win, sprite, x, y);
}

void	manage_sprites(t_data *screen, int x, int y)
{
	change_sprites(screen, screen->frame);
	if (screen->map[y][x] == 'P')
	{
		print_sprites(screen, x, y, screen->floor_sprite);
		print_sprites(screen, x, y, screen->player_sprite);
	}
	else if (screen->map[y][x] == '1')
		print_sprites(screen, x, y, screen->wall_sprite);
	else if (screen->map[y][x] == 'C')
	{
		print_sprites(screen, x, y, screen->floor_sprite);
		print_sprites(screen, x, y, screen->coll_sprite);
	}
	else if (screen->map[y][x] == 'E')
		print_sprites(screen, x, y, screen->end_sprite);
	else if (screen->map[y][x] == 'M')
	{
		print_sprites(screen, x, y, screen->floor_sprite);
		print_sprites(screen, x, y, screen->enemy_sprite);
	}
	else
		print_sprites(screen, x, y, screen->floor_sprite);
}
