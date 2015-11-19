#include "fdf.h"
#include <stdio.h>

int			render(t_data *data)
{
	size_t	h;
	size_t	w;

	h = 0;
	while (h < data->h)
	{
		w = 0;
		while (w < data->w)
		{
			printf("%d", data->map[h][w]);
			++w;
		}
		printf("\n");
		++h;
	}
	return (0);
}
