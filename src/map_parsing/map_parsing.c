#include "so_long.h"

int		ft_check_file_extension(char *map_file)
{
	char	*ptr;

	ptr = ft_strchr(map_file, '.');
	if (!ptr)
		ft_error_exit("map is not of ber type");
	if (ft_strncmp(++ptr, "ber", 4) != 0)
		ft_error_exit("map is not of ber type");
	return (1);
}

int		ft_open_map(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error_exit("couldn't open map");
	return (fd);
}

void	ft_get_window_dimensions(t_data *data)
{
	char	*line;
	size_t	rows;
	size_t	columns;

	line = get_next_line(data->fd);
	if (!line)
		ft_error_exit("invalid map");
	rows = 0;
	while (line)
	{
		columns = 0;
		while (line[columns])
			columns++;
		data->x_axis_map_size = columns;
		if (ft_strlen(line) != data->x_axis_map_size)
			ft_error_exit("invalid map");
		rows++;
		line = get_next_line(data->fd);
	}
	data->y_axis_map_size = rows;
	printf("%lu\n", data->y_axis_map_size);
	printf("%lu\n", data->x_axis_map_size);
}

void	ft_check_for_valid_map(char *map_file, t_data *data)
{
	ft_check_file_extension(map_file);
	data->fd = ft_open_map(map_file);
	ft_get_window_dimensions(data);
}

void	ft_get_map_dimensions(t_data *data)
{
	(void) data;
	return ;

}
