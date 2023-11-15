/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:39:29 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/14 09:39:29 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "structs.h"
# include "map.h"
# include "player.h"

t_game	*get_game(char *filename);
void	*delete_game(t_game *game);
void	print_steps(t_game *game);
void	print_end(t_game *game);

#endif