#include "so_long.h"

void	fn_check_map_file(char *map_file)
{
	(void) map_file;
}
	
void	fn_check_nb_args(int argc)
{
	if (argc != 2)
		fn_error_exit(NULL, EINVAL, 1);
}

void	fn_check_args(int argc, char **argv)
{
	fn_check_nb_args(argc);	
	(void) argv;
	/*
	fn_check_map_file(argv[1]);
	*/
}
