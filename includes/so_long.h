#ifndef SO_LONG_H
# define SO_LONG_H

#include "so_long.h"
#include "libft.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_data
{
	size_t	x_axis_map_size;
	size_t	y_axis_map_size;
	int		fd;
	char	**map;
}				t_data;

#include "prototypes.h"

#endif
