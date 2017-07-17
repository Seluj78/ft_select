# include "../includes/core/ft_select.h"

void				ft_putcharn(char c, size_t number)
{
	ft_putcharn_fd(c, number, 1);
}

void				ft_putcharn_fd(char c, size_t number, int file_descriptor)
{
	size_t			i;

	i = 0;
	while (i < number)
	{
		ft_putchar_fd(c, file_descriptor);
		i++;
	}
}