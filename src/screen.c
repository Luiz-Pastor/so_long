/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:58:26 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/14 10:11:45 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/screen.h"
#include "../inc/game.h"
#include "../inc/movement.h"

int	render(t_data *screen)
{
	int	x;
	int	y;

	y = 0;
	while (screen->map[y])
	{
		x = 0;
		while (screen->map[y][x])
		{
			if (screen->map[y][x] == 'P')
			{
				mlx_put_image_to_window(screen->mlx, screen->win, screen->floor_sprite, x * IMAGE_WEIGHT, y * IMAGE_HEIGHT);
				mlx_put_image_to_window(screen->mlx, screen->win, screen->player_sprite, x * IMAGE_WEIGHT, y * IMAGE_HEIGHT);
			}
			else if (screen->map[y][x] == '1')
				mlx_put_image_to_window(screen->mlx, screen->win, screen->wall_sprite, x * IMAGE_WEIGHT, y * IMAGE_HEIGHT);
			else if (screen->map[y][x] == 'C')
			{
				mlx_put_image_to_window(screen->mlx, screen->win, screen->floor_sprite, x * IMAGE_WEIGHT, y * IMAGE_HEIGHT);
				mlx_put_image_to_window(screen->mlx, screen->win, screen->coll_sprite, x * IMAGE_WEIGHT, y * IMAGE_HEIGHT);
			}
			else if (screen->map[y][x] == 'E')
				mlx_put_image_to_window(screen->mlx, screen->win, screen->end_sprite, x * IMAGE_WEIGHT, y * IMAGE_HEIGHT);
			else
				mlx_put_image_to_window(screen->mlx, screen->win, screen->floor_sprite, x * IMAGE_WEIGHT, y * IMAGE_HEIGHT);
			x++;
		}
		y++;
	}
	return (0);
}

void	end_game(t_data *screen)
{
	mlx_destroy_window(screen->mlx, screen->win);
	exit(0);
}

int	key_hook(int key, t_data *screen)
{
	if (key == ESC)
		end_game(screen);
	else if (key == LETTER_A || key == ROW_LEFT)
		move_left(screen->game);
	else if (key == LETTER_D || key == ROW_RIGHT)
		move_right(screen->game);
	else if (key == LETTER_W || key == ROW_UP)
		move_up(screen->game);
	else if (key == LETTER_S || key == ROW_DOWN)
		move_down(screen->game);
	return (0);
}

static int	set_sprites(t_data *screen)
{
	int	w;
	int	h;

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	screen->player_sprite = mlx_xpm_file_to_image(screen->mlx, PLAYER_INNER1, &w, &h);
	if (!screen->player_sprite)
		return (0);
	screen->wall_sprite = mlx_xpm_file_to_image(screen->mlx, WALL_INNER1, &w, &h);
	if (!screen->player_sprite)
		return (0);
	screen->floor_sprite = mlx_xpm_file_to_image(screen->mlx, BACKGROUND_INNER1, &w, &h);
	screen->end_sprite = mlx_xpm_file_to_image(screen->mlx, DOOR_CLOSE, &w, &h);
	screen->coll_sprite = mlx_xpm_file_to_image(screen->mlx, EGG, &w, &h);
	return (1);
}

t_data	*get_screen(int columns, int rows)
{
	t_data	*screen;

	screen = (t_data *) malloc(sizeof(t_data));
	if (!screen)
		return (NULL);
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, IMAGE_WEIGHT * columns, IMAGE_HEIGHT * rows, "so long!");
	if (!set_sprites(screen))
	{
		free(screen);
		return (NULL);
	}
	mlx_key_hook(screen->win, key_hook, screen);
	return (screen);
}
