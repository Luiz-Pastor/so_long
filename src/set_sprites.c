/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:07:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/17 10:12:14 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/structs.h"
#include "../inc/screen.h"

static int	push_player(t_data *screen)
{
	int		w;
	int		h;
	void	*mlx;

	w = 244;
	h = 244;
	mlx = screen->mlx;
	screen->sprites->player1 = mlx_xpm_file_to_image(mlx, PLY_INNER1, &w, &h);
	screen->sprites->player2 = mlx_xpm_file_to_image(mlx, PLY_INNER2, &w, &h);
	screen->sprites->player_down = mlx_xpm_file_to_image(mlx, PLY_DN, &w, &h);
	screen->sprites->player_up = mlx_xpm_file_to_image(mlx, PLY_UP, &w, &h);
	screen->sprites->player_right = mlx_xpm_file_to_image(mlx, PLY_RG, &w, &h);
	screen->sprites->player_left = mlx_xpm_file_to_image(mlx, PLY_LF, &w, &h);
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
	screen->sprites->enemy1 = mlx_xpm_file_to_image(mlx, EMY_INNER1, &w, &h);
	screen->sprites->enemy2 = mlx_xpm_file_to_image(mlx, EMY_INNER2, &w, &h);
	return (screen->end_sprite && \
	screen->sprites->enemy1 && screen->sprites->enemy2);
}
