#include "fdf.h"
#include "libft.h"
#include "ftlst.h"
#include <stdio.h>
#include <stdlib.h>

static int			line_load_fail(char **tab, const char *msg)
{
	ft_free_tab(tab);
	return (fail(msg));
}

static int			load_line(t_data *data, char **line_split, int y)
{
	static size_t	map_supposed_width = -1;
	char			**line_split_keep;
	unsigned int	x;

	if (data == NULL)
		return (map_supposed_width);
	else if (map_supposed_width == (size_t)-1)
		map_supposed_width = ft_tab_size((const char **)line_split);
	else if (map_supposed_width != ft_tab_size((const char **)line_split))
		return (line_load_fail(line_split, EMSG_INVALID_LINE_WIDTH));
	if (!(data->map[y] = ft_memalloc(sizeof(int) * (map_supposed_width + 1))))
		return (line_load_fail(line_split, EMSG_MALLOC));
	x = 0;
	line_split_keep = line_split;
	while (*line_split)
	{
		if (!ft_sisdigit(*line_split))
			return (line_load_fail(line_split_keep, EMSG_INVALID_NUMBER));
		data->map[y][x] = ft_atoi(*line_split);
		++line_split;
		++x;
	}
	ft_free_tab(line_split_keep);
	return (0);
}

int					load_map(t_data *data)
{
	unsigned int	i;
	size_t			map_supposed_height;
	t_lstiter		iter;

	map_supposed_height = lst_get_size(data->file_lines);
	if (map_supposed_height == 0)
		return (fail(EMSG_EMPTY_LIST));
	if (!(data->map = ft_memalloc(sizeof(int *) * (map_supposed_height + 1))))
		return (fail(EMSG_MALLOC));
	i = 0;
	init_iter(&iter, data->file_lines, increasing);
	while (lst_iterator_next(&iter))
	{
		if (load_line(data, ft_split(iter.data, FT_WHITESPACE), i) != 0)
			return (fail(EMSG_ENDING_LINE_LOAD));
		++i;
	}
	data->h = map_supposed_height;
	data->w = load_line(NULL, NULL, 0);
	lst_destroy(&data->file_lines, free);
	return (0);
}
