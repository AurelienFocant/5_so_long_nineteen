#ifndef SO_LONG_H
# define SO_LONG_H

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>

# define TILE_WIDTH 64
# define TILE_HEIGHT 64

# define WALL		'1'
# define PLAYER		'P'
# define EXIT		'E'
# define COLLECT	'C'
# define EMPTY		'0'

# define NO_MASK	 0
# define KEYDOWN	 2
# define RED_LIGHT	17

# define ESC	53
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define ARROW_UP		126 
# define ARROW_LEFT		123 
# define ARROW_DOWN		125 
# define ARROW_RIGHT	124 
# define UP		0 
# define LEFT	1 
# define DOWN	2 
# define RIGHT	3

# define FALSE 0
# define TRUE 1
# define ENDGAME 2

typedef struct	s_sprite
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*object;
	void	*empty_tile;
}				t_sprite;

typedef struct	s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	size_t			rows;
	size_t			columns;
	unsigned int	y_player_pos;
	unsigned int	x_player_pos;
	unsigned int	collectibles;
	t_sprite	sprite;
}				t_game;

#include "prototypes.h"

#endif
