/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:44:42 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 09:54:35 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display/display.h"

/*
** assumes screen has already been cleared (in refresh_screen.c)
** cm: positions the cursor at line l, column c
** ce: clear from the cursor to the end of the current line
** so: enter standout mode
** se: leave standout mode
** us: turn on underline mode
** ue: turn off underline mode
*/

void				remove_selected(t_data *data)
{
	ft_remove_nth_from_array(data->current_word, (void*)data->words
			, sizeof(char*), data->word_count);
	ft_remove_nth_from_array(data->current_word, (void*)data->highlighted_p
			, sizeof(int), data->word_count);
	data->word_count--;
	if (data->word_count <= 0)
		abort_exit(0);
	if (data->current_word >= data->word_count)
		data->current_word = 0;
}

static void			turn_on_special_text(t_data *data, int current)
{
	if (data->highlighted_p[current] == 1)
		ft_putstr_fd(tgetstr("so", NULL), 2);
	if (data->current_word == current)
		ft_putstr_fd(tgetstr("us", NULL), 2);
}

static void			turn_off_special_text(t_data *data, int current)
{
	if (data->current_word == current)
		ft_putstr_fd(tgetstr("ue", NULL), 2);
	if (data->highlighted_p[current] == 1)
		ft_putstr_fd(tgetstr("se", NULL), 2);
}

void				print_words(t_data *data)
{
	int				row;
	int				column;
	int				current;

	row = 0;
	while (row < data->height && row < data->word_count)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, row), 2);
		ft_putstr_fd(tgetstr("ce", NULL), 2);
		column = 0;
		while (((current = (data->height * column) + row)) < data->word_count)
		{
			turn_on_special_text(data, current);
			ft_putstr_fd(data->words[current], 2);
			turn_off_special_text(data, current);
			ft_putcharn_fd(' ', data->single_column_width
							- ft_strlen(data->words[current]), 2);
			column++;
		}
		row++;
	}
}
