/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:54:31 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/16 08:49:43 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <unistd.h>
# include <fcntl.h>
# include "../inc/structs.h"
# include "../libft/libft.h"

# define MAP_CH "01CEP"

t_map	*get_map(char *filename);
void	*delete_map(t_map *map);
void	print_map_info(t_map *map);

int		find_path(t_map *map);
int		map_locked(t_map *map);

int		count_collectable(t_map *map);
int		set_points(t_map *map);
t_map	*check_map(t_map *map);

#endif