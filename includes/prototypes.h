#include "so_long.h"

/*----------------  parse_map.c  ---------------*/
void	fn_get_window_dimensions(t_game *game, char *map_file);
void	fn_pass_map_into_struct(t_game *game, char *map_file);
void	fn_extract_game_info(t_game *game);
void	fn_parse_map(t_game *game, char *map_file);

/*----------------  check_args.c  ---------------*/
void	fn_error_exit(char *msg, int errnum, int exitcode);
void	fn_check_map_file(char *map_file);
void	fn_check_nb_args(int argc);
void	fn_check_args(int argc, char **argv);

/*----------------  main.c  ---------------*/
void	fn_check_args(int argc, char **argv);;
int	main(int argc, char **argv);
