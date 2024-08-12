#include "so_long.h"

void	fn_check_map_file(char *map_file)
{
	char	*ptr;

	ptr = ft_strchr(map_file, '.');
	if (!ptr)
		fn_error_exit("Wrong map extension", ENOEXEC, 3);
	if (ft_strncmp(++ptr, "ber", 4) != 0)
		fn_error_exit("Wrong map extension", ENOEXEC, 4);
}
	
void	fn_check_nb_args(int argc)
{
	if (argc != 2)
		fn_error_exit(NULL, EINVAL, 1);
}

void	fn_check_args(int argc, char **argv)
{
	fn_check_nb_args(argc);	
	fn_check_map_file(argv[1]);
}
