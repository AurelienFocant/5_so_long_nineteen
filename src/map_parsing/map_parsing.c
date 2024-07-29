#include "so_long.h"

void	ft_get_window_dimensions(t_data *data)
{
	int		fd;
	char	*line;
	size_t	rows;
	size_t	columns;

	fd = ft_open_map(data->map_file);
	line = ft_get_next_line(fd);
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
		line = ft_get_next_line(fd);
	}
	data->y_axis_map_size = rows;
	close(fd);
}

void	ft_print_map(t_data *data)
{
	unsigned int	row;

	row = 0;
	while (row < data->y_axis_map_size)
		printf("%s", data->map[row++]);
}

void	ft_parse_map(t_data *data)
{
	int				fd;
	unsigned int	row;
	char			*line;

	fd = ft_open_map(data->map_file);
	data->map = malloc(sizeof(char *) * (data->y_axis_map_size));
	line = ft_get_next_line(fd);
	if (!line)
		ft_error_exit("invalid map");
	row = 0;
	while (line)
	{
		data->map[row] = line;
		line = ft_get_next_line(fd);
		row++;
	}
	close(fd);
}
// don't forget to free the map !!
