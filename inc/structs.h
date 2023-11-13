/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:00:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/13 12:19:18 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_game t_game;
typedef struct s_map t_map;
typedef struct s_point t_point;
typedef struct s_player t_player;
typedef struct s_data t_data;

struct s_point
{
	int x;
	int y;	
};

struct s_player
{
	t_point coords;
	int collec;
};

struct s_data
{
	void	*mlx;
	void	*win;
	t_game	*game;
};

struct s_map
{
	char **map;
	int rows;
	int columns;
	t_point start;
	t_point out;
	int collectable;

	void	*player_sprite;
	void	*wall_sprite;
	void	*floor_sprite;
	void	*end_sprite;
	void	*coll_sprite;
};

struct s_game
{
	t_map *map;
	t_player *player;
	int steps;
};

#endif