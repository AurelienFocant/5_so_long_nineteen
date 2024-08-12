#include "so_long.h"

int	fn_iswall(char c)
{
	if (c == '1')
		return (1);
	else
		return (0);
}

void	fn_check_four_walls(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns)
		{
			if (i == 0 || i == game->rows - 1)
				if (!fn_iswall(game->map[i][j]))
					fn_free_and_exit("Map not properly walled off", ENOENT, 17, game);
			if (j == 0 || j == game->columns - 1)
				if (!fn_iswall(game->map[i][j]))
					fn_free_and_exit("Map not properly walled off", ENOENT, 18, game);
			j++;
		}
		i++;
	}
}

void	fn_check_map_for_errors(t_game *game)
{
	//	fn_check_if_rectangle(game);
	fn_check_four_walls(game);	
	//	fn_check_elements(game);
	//	fn_check_backtracking(game);
}
