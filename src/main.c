#include "so_long.h"

void	ft_check_args(int argc)
{
	if (argc != 2)
	{
		ft_printf("error args");
		exit(1);
	}
}

int main(int argc, char **argv)
{
	t_data	data;

	ft_check_args(argc);
	ft_check_for_valid_map(argv[1], &data);
	ft_init_data(&data);
	ft_minilibx_loop();

	exit(EXIT_SUCCESS);
}
