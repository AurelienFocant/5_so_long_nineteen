#ifndef SO_LONG_H
# define SO_LONG_H

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

# define HEIGHT 600
# define WIDTH 420

# define KEYDOWN 2
# define ESC 53

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct	s_data
{
	size_t	x_axis_map_size;
	size_t	y_axis_map_size;
	char	*map_file;
	char	**map;
	void	*mlx;
	void	*win;
	void	*img;
	int		bits_per_pixel;
	int		bytes_per_line;
	int		endian;
}				t_data;

#include "prototypes.h"

#endif
