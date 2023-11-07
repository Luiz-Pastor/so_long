#ifndef GAME_H
# define GAME_H

# include "structs.h"
# include "map.h"
# include "player.h"

t_game	*get_game(char *filename);
void	*delete_game(t_game *game);

#endif