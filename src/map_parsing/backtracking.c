#include "so_long.h"

int	fn_bt_move(t_game *game, int direction, int *exit)
{
	unsigned int		new_y;
	unsigned int		new_x;
	static unsigned int	count = 0;

	new_y = fn_find_new_y(game, direction);
	new_x = fn_find_new_x(game, direction);
	if (game->map[new_y][new_x] != WALL)
	{
		if (game->map[new_y][new_x] == EMPTY)
			fn_alter_map(game, new_y, new_x, EMPTY);
		else if (game->map[new_y][new_x] == COLLECT)
			fn_alter_map(game, new_y, new_x, COLLECT);
		else if (game->map[new_y][new_x] == EXIT && game->collectibles == 0)
		{
			ft_printf("%i\n", ++count);
			ft_printf("You win. That was impressive...\n");
		}
		else if (game->map[new_y][new_x] != EXIT)
			*exit = 1;
		if (game->map[new_y][new_x] != EXIT)
		{
			ft_printf("%i\n", ++count);
			return (1);
		}
		return (0);
	}
	return (0);
}

int	fn_backtracking(t_game *game, unsigned int collectibles, unsigned int exit)
{
	unsigned int direction;
	int	res;

	if (collectibles == 0 && exit == 1)
		return (1);
	
	direction = UP;
	while (direction <= RIGHT)
	{
		res = fn_bt_move(game, direction, &exit);
		if (!res)
		{
			direction++;
			continue;
		}
		if (
		if (fn_backtracking(game, collectibles, exit) == 1)
			return (1);
		fn_bt_move(game, (direction + 2) % 4);
		direction++;
	}
	return (0);
}

void	fn_copy_map(t_game *copy, t_game *game)
{
	unsigned int	i;

	copy->map = malloc(sizeof(char *) * (game->rows + 1));
	i = 0;
	while (i < game->rows)
	{
		copy->map[i] = ft_strdup(game->map[i]);
		i++;
	}
	copy->map[i] = NULL;
}

void	fn_check_backtracking(t_game *game)
{
	unsigned int	collectibles;
	unsigned int	exit;
	t_game			game_copy;

	fn_copy_map(&game_copy, game);
	collectibles = 0;
	exit = 0;
	if (fn_backtracking(&game_copy, collectibles, exit))
		printf("backtrack ok");
	else
		printf("backtrack nonk");
	fn_free_map(&game_copy);
}
