#include <stdlib.h>
#include "fdf.h"

void	free_map(t_data *data)
{
	unsigned int	y;

	y = 0;
	while (y < data->h)
	{
		free(data->map[y]);
		++y;
	}
	free(data->map);
}
