#include "fdf.h"
#include "libft.h"

int		handle_mouse_event(int button, int x, int y, t_data *data)
{
	(void)data;
	ft_putstr("Mouse event : ");
	ft_putnbr(button);
	ft_putstr(" ");
	ft_putnbr(x);
	ft_putstr(" ");
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}
