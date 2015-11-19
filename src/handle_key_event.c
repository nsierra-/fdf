#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

int		handle_key_event(int key, t_data *data)
{
	(void)data;
	ft_putstr("Key event : ");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
	{
		free_map(data);
		exit(0);
	}
	return (0);
}
