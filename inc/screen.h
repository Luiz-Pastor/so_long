/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:00:23 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/13 12:12:32 by lpastor-         ###   ########.fr       */
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

# define PLAYER_INNER1 "textures/player/player_inner1.xpm"

t_data	*get_screen(t_game *game);
int	render(t_data *screen);

#endif