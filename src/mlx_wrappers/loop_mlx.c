#include "so_long.h"

int	fn_exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	fn_free_map(game);
	exit(0);
}

int	fn_key_hook(int key, t_game *game)
{
	if (key == ESC)
		fn_exit_game(game);
	if (key == ARROW_UP || key == KEY_W)
	{
		fn_assign_sprite(game, UP);
		fn_move(game, UP);
	}
	if (key == ARROW_LEFT || key == KEY_A)
	{
		fn_assign_sprite(game, LEFT);
		fn_move(game, LEFT);
	}
	if (key == ARROW_DOWN || key == KEY_S)
	{
		fn_assign_sprite(game, DOWN);
		fn_move(game, DOWN);
	}
	if (key == ARROW_RIGHT || key == KEY_D)
	{
		fn_assign_sprite(game, RIGHT);
		fn_move(game, RIGHT);
	}
	return (0);
}

void	fn_loop_mlx(t_game *game)
{
	mlx_hook(game->win, KEYDOWN, NO_MASK, fn_key_hook, game);
	mlx_hook(game->win, RED_LIGHT, NO_MASK, fn_exit_game, game);
	mlx_loop_hook(game->mlx, fn_draw_map, game);
	mlx_loop(game->mlx);
}
