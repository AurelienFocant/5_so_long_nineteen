#include "so_long.h"

void	fn_move_up(t_game *game)
{
	unsigned int	y;
	unsigned int	x;

	y = game->y_player_pos;
	x = game->x_player_pos;
	(void) y;
	(void) x;
	/*
	if (game->map[y-1][x] != WALL)
	{
		if (game->map[y-1][x] == EMPTY)
			fn_move_to_empty(game, y, x);
		else if (game->map[y-1][x] == COLLECT)
			fn_move_to_collectible(game, y, x);
		else if (game->map[y-1][x] == EXIT)
			fn_move_to_exit(game, y, x);
	}
	*/
}
