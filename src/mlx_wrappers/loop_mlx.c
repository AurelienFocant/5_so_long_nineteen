#include "so_long.h"

int	fn_exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
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
		fn_move_up(game);
	/*
	   if (key == ARROW_LEFT || key == KEY_A)
	   fn_move_left(game);
	   if (key == ARROW_DOWN || key == KEY_S)
	   fn_move_down(game);
	   if (key == ARROW_RIGHT || key == KEY_D)
	   fn_move_right(game);
	 */
	return (0);
}

void	fn_loop_mlx(t_game *game)
{
	mlx_hook(game->win, KEYDOWN, 0, fn_key_hook, game);
	mlx_hook(game->win, RED_LIGHT, 0, fn_exit_game, game);
	mlx_loop_hook(game->mlx, fn_draw_map, game);
	mlx_loop(game->mlx);
}
