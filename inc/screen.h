/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:00:23 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/16 12:54:00 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include <mlx.h>
# include <stdlib.h>
# include "structs.h"

enum {
	LETTER_W = 13,
	LETTER_A = 0,
	LETTER_S = 1,
	LETTER_D = 2,
	LETTER_Q = 12,
	ESC = 53,
	ROW_UP = 126,
	ROW_LEFT = 123,
	ROW_DOWN = 125,
	ROW_RIGHT = 124
};

# define IMAGE_HEIGHT 144
# define IMAGE_WEIGHT 144

# define PLY_INNER1		"textures/player/player_inner1.xpm"
# define PLY_INNER2		"textures/player/player_inner1.xpm"
# define WALL_INNER1	"textures/wall/wall_state1.xpm"
# define WALL_INNER2	"textures/wall/wall_state3.xpm"
# define BACK_INNER1	"textures/background/tile001.xpm"
# define BACK_INNER2	"textures/background/tile001.xpm"
# define DOOR_CLOSE		"textures/door/door_close.xpm"
# define COLL1			"textures/collec/egg.xpm"
# define COLL2			"textures/collec/egg.xpm"

t_data	*get_screen(int columns, int rows);
int		render(t_data *screen);
int		end_game(t_data *screen);

int		push_images(t_data *screen);
void	manage_sprites(t_data *screen, int x, int y);
void	change_sprites(t_data *screen, int frame);

#endif