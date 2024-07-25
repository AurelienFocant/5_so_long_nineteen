
/*----------------  data_init.c  ---------------*/
void	ft_init_data(t_data *data);

/*----------------  errors.c  ---------------*/
void	ft_error_exit(char *msg);

/*----------------  main.c  ---------------*/
void	ft_check_args(int argc);
int main(int argc, char **argv);

/*----------------  map_parsing.c  ---------------*/
void	ft_check_for_valid_map(char *map_file);
void	ft_get_map_dimensions(&data);;
void	ft_parse_map(char *map_file);

/*----------------  minilibx_loop.c  ---------------*/
void	ft_minilibx_loop(void);

