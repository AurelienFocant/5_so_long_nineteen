#include "so_long.h"

void	fn_error_exit(char *msg, int errnum, int exitcode)
{
	if (!errno)
		errno = errnum;
	perror(msg);
	exit(exitcode);	
}

void	fn_free_null(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	fn_free_map(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (game->map[i])
		fn_free_null(game->map[i++]);
	free(game->map);
	game->map = NULL;
}

int		fn_is_sprite_null(t_sprite sprite)
{
	if (sprite.wall == NULL)
		return (1);
	if (sprite.player == NULL)
		return (1);
	if (sprite.exit == NULL)
		return (1);
	if (sprite.object == NULL)
		return (1);
	if (sprite.empty_tile == NULL)
		return (1);
	return (0);
}
