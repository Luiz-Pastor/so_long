/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:00:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/02 10:05:33 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_game t_game;
typedef struct s_map t_map;

struct s_game
{
	t_map *map;
};


struct s_map
{
	char **map;
	int columns;
	int rows;
	/*
	int objectives;
	*/
};

#endif