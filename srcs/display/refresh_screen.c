/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:44:53 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 09:45:08 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display/display.h"

/*
** called by signal ==> can't have env as argument
*/

static void			get_window_size(t_data *data)
{
	struct winsize	window;

	if (ioctl(0, TIOCGWINSZ, &window) == -1)
	{
		ft_printf("ft_select: Error whilst getting window size.\n");
		abort_exit(0);
	}
	data->width = window.ws_col;
	data->height = window.ws_row;
}

static int			will_fit_on_screen(t_data *data)
{
	int				number_of_columns;

	number_of_columns = data->word_count / data->height + 1;
	return ((number_of_columns * data->single_column_width) < data->width);
}

void				refresh_screen(int signum)
{
	t_data	*data;

	(void)signum;
	data = get_set_data(NULL);
	get_window_size(data);
	cl_screen(data);
	if (will_fit_on_screen(data))
		print_words(data);
	else
		ft_putstr_fd("Not enough room.", 2);
}
