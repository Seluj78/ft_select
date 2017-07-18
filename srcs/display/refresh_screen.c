
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

static int			will_fit_on_screen(t_data *env)
{
	int				number_of_columns;

	number_of_columns = env->word_count / env->height + 1;
	return ((number_of_columns * env->single_column_width) < env->width);
}

void				refresh_screen(int signum)
{
	t_data	*env;

	(void)signum;
	env = get_set_data(NULL);
	get_window_size(env);
	clear_screen_from_text(env);
	if (will_fit_on_screen(env))
		print_words(env);
	else
		ft_putstr_fd("Not enough room.", 2);
}
