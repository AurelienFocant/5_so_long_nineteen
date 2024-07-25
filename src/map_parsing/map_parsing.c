#include "so_long.h"

void	ft_check_for_valid_map(char *map_file)
{
	char	*ptr;

	ptr = ft_strchr(map_file, '.');
	if (!ptr)
		ft_error_exit("map is not of ber type");
	if (ft_strncmp(++ptr, "ber", 4) != 0)
		ft_error_exit("map is not of ber type");
}

void	ft_get_map_dimensions(&data);
{
}

void	ft_parse_map(char *map_file)
{
	int	fd;	

	ft_check_for_valid_map(map_file);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_error_exit("open failed");
}
