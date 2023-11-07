#ifndef PLAYER_H
# define PLAYER_H

# include "structs.h"
# include "map.h" 

t_player	*get_player(t_map *map);
void	*delete_player(t_player *player);

#endif