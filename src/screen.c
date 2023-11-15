/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:58:26 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/15 10:42:30 by lpastor-         ###   ########.fr       */
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
			manage_sprites(screen, x, y);
			x++;
		}
		y++;
	}
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
	screen->player_sprite = mlx_xpm_file_to_image(mlx, PLAYER_INNER1, &w, &h);
	if (!screen->player_sprite)
		return (0);
	screen->wall_sprite = mlx_xpm_file_to_image(mlx, WALL_INNER1, &w, &h);
	if (!screen->player_sprite)
		return (0);
	screen->floor_sprite = mlx_xpm_file_to_image(mlx, BACK_INNER1, &w, &h);
	if (!screen->floor_sprite)
		return (0);
	screen->end_sprite = mlx_xpm_file_to_image(mlx, DOOR_CLOSE, &w, &h);
	if (!screen->end_sprite)
		return (0);
	screen->coll_sprite = mlx_xpm_file_to_image(mlx, EGG, &w, &h);
	if (!screen->coll_sprite)
		return (0);
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
	screen->win = mlx_new_window(screen->mlx, weight, height, "so long!");
	if (!set_sprites(screen))
	{
		exit(1);
		mlx_destroy_window(screen->mlx, screen->win);
		free(screen);
		return (NULL);
	}
	mlx_key_hook(screen->win, key_hook, screen);
	mlx_loop_hook(screen->mlx, render, screen);
	mlx_hook(screen->win, 17, 0, end_game, screen);
	return (screen);
}
