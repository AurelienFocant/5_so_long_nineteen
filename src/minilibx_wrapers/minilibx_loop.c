#include "so_long.h"

void	ft_free_map(t_data *data)
{
	unsigned int	row;

	row = 0;
	while (row < data->y_axis_map_size)
		free(data->map[row++]);
	free(data->map);
}

int	ft_close_win(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		ft_free_map(data);
		exit(0);
	}
	ft_printf("the key was %i\n", key);
	return (0);
}

void	ft_minilibx_loop(t_data *data)
{
	mlx_hook(data->win, KEYDOWN, 0, ft_close_win, data);
	mlx_loop(data->mlx);
}
