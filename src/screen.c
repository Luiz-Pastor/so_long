/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:58:26 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/13 11:58:16 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/screen.h"
#include "../inc/game.h"

int	render(t_data *screen)
{
	mlx_put_image_to_window(screen->mlx, screen->win, screen->game->map->player_sprite, 10, 10);
	return 0;
}

void	end_game(t_data *screen)
{
	mlx_destroy_window(screen->mlx, screen->win);
	delete_game(screen->game);
	exit(0);
}

int key_hook(int key, t_data *screen)
{
	if (key == ESC)
		end_game(screen);
	return (0);
}

static int	set_sprites(t_data *screen)
{
	int w = IMAGE_WEIGHT;
	int h = IMAGE_HEIGHT;
	screen->game->map->player_sprite = mlx_xpm_file_to_image(screen->mlx, PLAYER_INNER1, &w, &h);
	if (!screen->game->map->player_sprite)
		return (0);
		
	return (1);
}

t_data	*get_screen(t_game *game)
{
	t_data	*screen;

	screen = (t_data *) malloc(sizeof(t_data));
	if (!screen)
		return (NULL);

	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, /*IMAGE_WEIGHT * game->map->columns*/1080, /*IMAGE_HEIGHT * game->map->rows*/1098, "so long!");
	
	screen->game = game;

	if (!set_sprites(screen))
	{
		free(screen);
		return NULL;
	}

	mlx_key_hook(screen->win, key_hook, screen);
	return (screen);
}