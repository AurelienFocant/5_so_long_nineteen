#include "so_long.h"

void	ft_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		//free map
		ft_error_exit("mlx init failed");
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "plouf");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_get_data_addr(data->img, &(data->bits_per_pixel), \
			&(data->bytes_per_line), &(data->endian));
}
