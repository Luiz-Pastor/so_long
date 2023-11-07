#include <stdlib.h>
#include "../inc/game.h"

void	*delete_game(t_game *game)
{
	if (!game)
		return (NULL);

	if (game->map)
		delete_map(game->map);

	if (game->player)
		delete_player(game->player);
	
	free(game);
	return (NULL);
}

t_game	*get_game(char *filename)
{
	t_game	*game;

	if (!filename)
		return (NULL);

	game = (t_game *) malloc(sizeof(t_game));
	if (!game)
		return (NULL);

	game->map = get_map(filename);
	if (!(game->map))
	{
		printf("Error reading the map\n");
		return (free(game), NULL);
	}

	game->player = get_player(game->map);
	if (!game->player)
		return (delete_game(game));

	game->steps = 0;

	return (game);	
}
