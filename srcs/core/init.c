/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:47:57 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 09:23:32 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/init.h"

static void		init_term_helper(t_data *data)
{
	data->term->c_lflag &= ~(ICANON);
	data->term->c_lflag &= ~(ECHO);
	data->term->c_cc[VMIN] = 1;
	data->term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, data->term) == -1)
		exit(1);
	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
}

void			init_term(t_data *data)
{
	char			*terminal_name;
	struct termios	save_tattr;

	if (!(terminal_name = getenv("TERM")))
	{
		ft_printf("Error getting data->TERM\n");
		exit(1);
	}
	if (tgetent(NULL, terminal_name) <= 0)
	{
		ft_putendl_fd("Error getting data->TERM", 2);
		exit(1);
	}
	if (tcgetattr(0, &save_tattr) != 0)
	{
		ft_printf("ft_select: tcgetattr error when trying");
		ft_printf(" to save terminal attributes\n");
		return ;
	}
	else if ((data->term = (struct termios*)malloc(sizeof(struct termios))))
		ft_memcpy(data->term, &save_tattr, sizeof(struct termios));
	init_term_helper(data);
}

void			init_data(t_data *data, int argc, char **argv)
{
	data->words = argv + 1;
	data->word_count = argc - 1;
	data->highlighted_p = malloc((argc - 1) * sizeof(int));
	ft_bzero(data->highlighted_p, (argc - 1) * sizeof(int));
	data->current_word = 0;
	data->single_column_width = get_longest_word_length(data) + 2;
	init_term(data);
}
