#include "so_long.h"
#include <string.h>
void	fn_check_nb_args(int argc)
{
	int		errnum;
	char	*err_msg;

	if (argc != 2)
	{
		errnum = 4;
		err_msg = strerror(errnum);
		ft_printf("%s\n", err_msg);
		exit(1);
	}
}

void	fn_check_args(int argc, char **argv)
{
	fn_check_nb_args(argc);	
//	fn_check_map_file(argv[1]);
}
