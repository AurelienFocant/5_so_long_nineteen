#include "so_long.h"

/*----------------  draw_map.c  ---------------*/
void	fn_draw_tile(t_game *game, void *sprite, unsigned int x, unsigned int y);
void	fn_draw_map(t_game *game);

/*----------------  moving.c  ---------------*/
void	fn_move_up(t_game *game);

/*----------------  parse_map.c  ---------------*/
void	fn_get_window_dimensions(t_game *game, char *map_file);
void	fn_pass_map_into_struct(t_game *game, char *map_file);
void	fn_extract_game_info(t_game *game);
void	fn_parse_map(t_game *game, char *map_file);

/*----------------  setup_mlx.c  ---------------*/
void	fn_retrieve_sprites(t_game *game);
void	fn_setup_mlx(t_game *game);

/*----------------  loop_mlx.c  ---------------*/
void	fn_exit_game(t_game *game);
int	fn_key_hook(int key, t_game *game);

/*----------------  error_utils.c  ---------------*/
void	fn_error_exit(char *msg, int errnum, int exitcode);
void	fn_free_null(char *ptr);
void	fn_free_map(t_game *game);
int		fn_is_sprite_null(t_sprite sprite);

/*----------------  check_args.c  ---------------*/
void	fn_check_map_file(char *map_file);
void	fn_check_nb_args(int argc);
void	fn_check_args(int argc, char **argv);

/*----------------  main.c  ---------------*/
void	fn_init_struct(t_game *game);
int	main(int argc, char **argv);
