/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:00:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/11/16 09:18:49 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_game	t_game;
typedef struct s_map	t_map;
typedef struct s_point	t_point;
typedef struct s_player	t_player;
typedef struct s_data	t_data;
typedef struct s_images	t_images;

struct s_point
{
	int	x;
	int	y;	
};

struct s_player
{
	t_point	coords;
	int		collec;
};

struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	void		*player_sprite;
	void		*wall_sprite;
	void		*floor_sprite;
	void		*end_sprite;
	void		*coll_sprite;
	t_game		*game;
	int			count;
	int			frame;
	t_images	*sprites;
};

struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	t_point	start;
	t_point	out;
	int		collectable;
};

struct s_game
{
	t_map		*map;
	t_player	*player;
	t_data		*screen;
	int			steps;
};

struct s_images
{
	void	*player1;
	void	*player2;
	void	*wall1;	
	void	*wall2;	
	void	*back1;	
	void	*back2;	
	void	*end1;	
	void	*end2;	
	void	*coll1;	
	void	*coll2;	
};

#endif