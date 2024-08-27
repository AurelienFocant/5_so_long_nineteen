/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:02:05 by afocant           #+#    #+#             */
/*   Updated: 2024/08/27 14:02:06 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fn_check_if_rectangle(t_game *game)
{
	size_t	i;

	if (game->rows < 3 || game->columns < 3)
		fn_free_and_exit("Map too small", ENOENT, 18, game);
	i = 0;
	while (i < game->rows)
	{
		if (ft_strlen(game->map[i]) - 1 != game->columns)
			fn_free_and_exit("Map is not a rectangle", ENOENT, 19, game);
		i++;
	}
}

int	fn_iswall(char c)
{
	if (c == '1')
		return (1);
	else
		return (0);
}

void	fn_check_four_walls(t_game *game)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->columns)
		{
			if (row == 0 || row == game->rows - 1)
				if (!fn_iswall(game->map[row][col]))
					fn_free_and_exit("Map not properly walled off",
						ENOENT, 17, game);
			if (col == 0 || col == game->columns - 1)
				if (!fn_iswall(game->map[row][col]))
					fn_free_and_exit("Map not properly walled off",
						ENOENT, 18, game);
			col++;
		}
		row++;
	}
}

void	fn_check_elements(t_game *game)
{
	unsigned int	exit;
	unsigned int	player;
	unsigned int	row;
	unsigned int	col;

	exit = 0;
	player = 0;
	row = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->columns)
		{
			if (!ft_strchr("01CEP", game->map[row][col]))
				fn_free_and_exit("Invalid element in map", ENOENT, 18, game);
			if (game->map[row][col] == EXIT)
				exit++;
			if (game->map[row][col] == PLAYER)
				player++;
			col++;
		}
		row++;
	}
	if (game->collectibles < 1 || exit != 1 || player != 1)
		fn_free_and_exit("Invalid number of elements in map", ENOENT, 19, game);
}

void	fn_check_map_for_errors(t_game *game)
{
	fn_check_if_rectangle(game);
	fn_check_four_walls(game);
	fn_check_elements(game);
	fn_start_flooding(game);
}
