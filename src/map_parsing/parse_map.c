#include "so_long.h"

void	fn_get_window_dimensions(t_game *game, char *map_file)
{
	int		fd;
	int		nl;
	char	*line;
	
	fd = open(map_file, O_RDONLY);
	line = ft_get_next_line(fd);	
	if (!line)
		fn_error_exit(NULL, errno, 2);
	nl = 1;
	game->columns = ft_strlen(line) - nl;
	game->rows = 0;
	while (line)
	{
		game->rows += 1;
		free(line);
		line = ft_get_next_line(fd);	
	}
	close(fd);
}

void	fn_pass_map_into_struct(t_game *game, char *map_file)
{
	int		fd;
	char	*line;
	
	fd = open(map_file, O_RDONLY);
	line = ft_get_next_line(fd);	
	if (!line)
		fn_error_exit(NULL, errno, 3);
	game->map = malloc(sizeof(char *) * game->rows);
	if (!game->map)
		fn_error_exit(NULL, ENOMEM, 4);
	while (line)
	{
		game->map[game->rows] = line;
		game->rows += 1;
		line = ft_get_next_line(fd);	
	}
	close(fd);
}

void	fn_parse_map(t_game *game, char *map_file)
{
	fn_get_window_dimensions(game, map_file);
	fn_pass_map_into_struct(game, map_file);
	/*
	fn_check_map_for_errors(game);
	fn_extract_game_info(game);
	*/
}
