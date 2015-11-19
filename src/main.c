#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "libft.h"
#include "fdf.h"

static int		treat_line(const char *line, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	ft_putendl(line);
	lst_push_back(data->file_lines, (void *)ft_strdup(line));
	return (0);
}

static int		init_data(t_data *data)
{
	if (!(data->mlx_context = mlx_init()))
		return (fail(EMSG_MLX_INIT));
	else if (!(data->window = mlx_new_window(data->mlx_context, WINDOW_SIZE, "teub")))
		return (fail(EMSG_MLX_WINDOW));
	data->map = NULL;
	data->file_lines = new_lst();
	return (0);
}

static void		init_hooks(t_data *data)
{
	mlx_expose_hook(data->window, render, data);
	mlx_loop_hook(data->mlx_context, render, data);
	mlx_key_hook(data->window, handle_key_event, data);
	mlx_mouse_hook(data->window, handle_mouse_event, data);
}

int				main(int ac, const char **av)
{
	t_data		data;

	(void)av;
	if (ac != 2)
		return (fail(USAGE_STR));
	init_data(&data);
	if (for_each_line_file(av[1], treat_line, O_RDONLY, &data) != 0)
		return (fail(EMSG_FILE));
	if (load_map(&data) != 0)
		return (fail(EMSG_TERMINATE));
	init_hooks(&data);
	mlx_loop(data.mlx_context);
	return (0);
}
