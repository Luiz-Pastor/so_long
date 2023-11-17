/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:58:26 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/17 10:31:43 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/screen.h"
#include "../inc/game.h"
#include "../inc/movement.h"

#define FRAMES_CHANGE 50

int	render(t_data *screen)
{
	int		x;
	int		y;
	char	*steps;

	y = 0;
	screen->count++;
	mlx_clear_window(screen->mlx, screen->win);
	if (screen->count >= FRAMES_CHANGE)
	{
		screen->count = 0;
		screen->frame = (screen->frame + 1) % 2;
	}
	while (screen->map[y])
	{
		x = 0;
		while (screen->map[y][x])
			manage_sprites(screen, x++, y);
		y++;
	}
	steps = ft_itoa(screen->game->steps);
	mlx_string_put(screen->mlx, screen->win, 50, 50, 0xFFF, steps);
	free(steps);
	return (0);
}

int	end_game(t_data *screen)
{
	mlx_destroy_window(screen->mlx, screen->win);
	print_end(screen->game);
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
	int		w;
	int		h;
	void	*mlx;

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = screen->mlx;
	if (!push_images(screen))
		return (0);
	change_sprites(screen, 0);
	return (1);
}

t_data	*get_screen(int columns, int rows)
{
	t_data	*screen;
	int		weight;
	int		height;

	weight = IMAGE_WEIGHT * columns;
	height = IMAGE_HEIGHT * rows;
	screen = (t_data *) malloc(sizeof(t_data));
	if (!screen)
		return (NULL);
	screen->mlx = mlx_init();
	screen->sprites = (t_images *) malloc(sizeof(t_images));
	screen->win = mlx_new_window(screen->mlx, weight, height, "so long!");
	if (!screen->sprites || !set_sprites(screen))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	screen->count = 0;
	screen->frame = 1;
	screen->ply_priority = 0;
	mlx_key_hook(screen->win, key_hook, screen);
	mlx_loop_hook(screen->mlx, render, screen);
	mlx_hook(screen->win, 17, 0, end_game, screen);
	return (screen);
}
