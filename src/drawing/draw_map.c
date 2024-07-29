#include "so_long.h"

void	ft_retrieve_sprites(t_data *data)
{
	int	img_width;
	int	img_height;

	data->sprite.wall = mlx_xpm_file_to_image(data->mlx, "/Users/afocant/cursus_nineteen/5_so_long/misc/sprites/rock.xpm", &img_width, &img_height);
}

void	ft_draw_tile(void *sprite, int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, sprite, x * TILE_WIDTH, y * TILE_HEIGHT);
}

void	ft_draw_map(t_data *data)
{
	unsigned int	row;
	unsigned int	column;

	row = 0;
	while (row < data->y_axis_map_size)
	{
		column = 0;
		while (column < data->x_axis_map_size)
		{
			if (data->map[row][column] == '1')
				ft_draw_tile(data->sprite.wall, column, row, data);
			else if (data->map[row][column] == '\n')
				printf("\n");
			else
				printf("F");
			column++;
		}
		row++;	
	}
}
