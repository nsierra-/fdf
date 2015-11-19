#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

static int		treat_line(const char *line, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	lst_push_back(data->file_lines, (void *)line);
	return (0);
}

static void		init_data(t_data *data)
{
	data->map = NULL;
	data->file_lines = new_lst();
}

int				main(int ac, const char **av)
{
	t_data		data;

	if (ac != 2)
		return (fail(USAGE_STR));
	init_data(&data);
	if (for_each_line_file(av[1], treat_line, O_RDONLY, &data) != 0)
		return (fail(EMSG_FILE));
	if (load_map(&data) != 0 || render(&data) != 0)
		return (fail(EMSG_TERMINATE));
	return (0);
}
