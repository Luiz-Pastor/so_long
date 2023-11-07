#include <stdlib.h>
#include "../inc/player.h"

void	*delete_player(t_player *player)
{
	if (!player)
		return (NULL);

	free(player);
	return (NULL);
}

t_player	*get_player(t_map *map)
{
	t_player *player;

	if (!map)
		return (NULL);
	player = (t_player *) malloc(sizeof(t_player));
	if (!player)
		return (NULL);

	player->coords.x = map->start.x;
	player->coords.y = map->start.y;
	player->collec = 0;

	return (player);
}