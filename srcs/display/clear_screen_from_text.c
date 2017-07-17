/*
** tgoto(tgetstr("cm", NULL), row, column)
** ==> moves cursor to (row, column)
** tgetstr("ce", NULL)
** ==> clears from where the cursor is to the end of that line
*/
#include "display/display.h"


void			clear_screen_from_text(t_data *data)
{
	int				i;

	i = 0;
	while (i < data->height)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, i), 2);
		ft_putstr_fd(tgetstr("ce", NULL), 2);
		i++;
	}
}
