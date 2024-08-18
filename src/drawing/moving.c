#include "so_long.h"

unsigned int	fn_find_new_y(t_game *game, int direction)
{
	if (direction == UP)
		return (game->y_player_pos - 1);
	if (direction == LEFT)
		return (game->y_player_pos);
	if (direction == DOWN)
		return (game->y_player_pos + 1);
	if (direction == RIGHT)
		return (game->y_player_pos);
	return (0);
}

unsigned int	fn_find_new_x(t_game *game, int direction)
{
	if (direction == UP)
		return (game->x_player_pos);
	if (direction == LEFT)
		return (game->x_player_pos - 1);
	if (direction == DOWN)
		return (game->x_player_pos);
	if (direction == RIGHT)
		return (game->x_player_pos + 1);
	return (0);
}

void	fn_alter_map(t_game *game, unsigned int new_y, unsigned int new_x, char tile)
{
	unsigned int	old_y;
	unsigned int	old_x;

	old_y = game->y_player_pos;
	game->y_player_pos = new_y;
	old_x = game->x_player_pos;
	game->x_player_pos = new_x;
	game->map[old_y][old_x] = EMPTY;
	if (tile == COLLECT)
		game->collectibles--;
	if (tile == EXIT)
		game->map[new_y][new_x] = EXIT;
	else
		game->map[new_y][new_x] = PLAYER;
}

void	fn_assign_sprite(t_game *game, int direction)
{
	int	img_width;
	int	img_height;


	if (direction == UP)
		game->sprite.player = mlx_xpm_file_to_image(game->mlx, "misc/sprites/link_up.xpm", &img_width, &img_height);
	else if (direction == LEFT)
		game->sprite.player = mlx_xpm_file_to_image(game->mlx, "misc/sprites/link_left.xpm", &img_width, &img_height);
	else if (direction == RIGHT)
		game->sprite.player = mlx_xpm_file_to_image(game->mlx, "misc/sprites/link_right.xpm", &img_width, &img_height);
	else if (direction == DOWN)
		game->sprite.player = mlx_xpm_file_to_image(game->mlx, "misc/sprites/link_down.xpm", &img_width, &img_height);

}

int	fn_move(t_game *game, int direction)
{
	unsigned int		new_y;
	unsigned int		new_x;
	static unsigned int	count = 0;

	new_y = fn_find_new_y(game, direction);
	new_x = fn_find_new_x(game, direction);
	if (game->map[new_y][new_x] != WALL)
	{
		if (game->map[new_y][new_x] == EXIT)
			if (game->collectibles == 0)
			{
				ft_printf("%i\n", ++count);
				return (ENDGAME);
			}
			else
				return (FALSE);
		else
		{
			ft_printf("%i\n", ++count);
			fn_alter_map(game, new_y, new_x, game->map[new_y][new_x]);
		}
		return (TRUE);
	}
	return (FALSE);
}
