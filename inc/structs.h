/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:00:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/03 12:56:16 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_game t_game;
typedef struct s_map t_map;
typedef struct s_point t_point;
typedef struct s_player t_player;

struct s_point
{
	int x;
	int y;	
};

struct s_player
{
	t_point coords;
};

struct s_game
{
	t_map *map;
};

struct s_map
{
	char **map;
	int rows;
	int columns;
	t_point start;
	t_point out;
	int collectable;
};

#endif