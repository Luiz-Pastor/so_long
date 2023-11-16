/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:07:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/16 12:54:27 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/structs.h"
#include "../inc/screen.h"

#include <stdio.h>

static int	push_player(t_data *screen)
{
	int		w;
	int		h;
	void	*mlx;

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = screen->mlx;
	screen->sprites->player1 = mlx_xpm_file_to_image(mlx, PLY_INNER1, &w, &h);
	screen->sprites->player2 = mlx_xpm_file_to_image(mlx, PLY_INNER2, &w, &h);
	return (screen->sprites->player1 && screen->sprites->player2);
}

static int	push_wall(t_data *screen)
{
	int		w;
	int		h;
	void	*mlx;

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = screen->mlx;
	screen->sprites->wall1 = mlx_xpm_file_to_image(mlx, WALL_INNER1, &w, &h);
	screen->sprites->wall2 = mlx_xpm_file_to_image(mlx, WALL_INNER2, &w, &h);
	return (screen->sprites->wall1 && screen->sprites->wall2);
}

static int	push_back(t_data *screen)
{
	int		w;
	int		h;
	void	*mlx;

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = screen->mlx;
	screen->sprites->back1 = mlx_xpm_file_to_image(mlx, BACK_INNER1, &w, &h);
	screen->sprites->back2 = mlx_xpm_file_to_image(mlx, BACK_INNER2, &w, &h);
	return (screen->sprites->back1 && screen->sprites->back2);
}

static int	push_coll(t_data *screen)
{
	int		w;
	int		h;
	void	*mlx;

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = screen->mlx;
	screen->sprites->coll1 = mlx_xpm_file_to_image(mlx, COLL1, &w, &h);
	screen->sprites->coll2 = mlx_xpm_file_to_image(mlx, COLL2, &w, &h);
	return (screen->sprites->coll1 && screen->sprites->coll2);
}

int	push_images(t_data *screen)
{
	int		w;
	int		h;
	void	*mlx;

	w = IMAGE_WEIGHT;
	h = IMAGE_HEIGHT;
	mlx = screen->mlx;
	if (!push_player(screen) || !push_wall(screen) || !push_back(screen))
		return (0);
	if (!push_coll(screen))
		return (0);
	screen->end_sprite = mlx_xpm_file_to_image(mlx, DOOR_CLOSE, &w, &h);
	return (screen->end_sprite != NULL);
}
