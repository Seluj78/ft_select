/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:24:08 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 09:54:14 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_select.h"

static void			select_deselect(t_data *data)
{
	if (data->highlighted_p[data->current_word] == 1)
		data->highlighted_p[data->current_word] = 0;
	else
		data->highlighted_p[data->current_word] = 1;
	data->current_word = (data->current_word == data->word_count - 1
								? 0 : data->current_word + 1);
}

static void			handle_up_down(t_data *data, int keycode)
{
	if (keycode == KEY_DOWN)
	{
		data->current_word++;
		if (data->current_word > data->word_count - 1)
			data->current_word = 0;
	}
	else if (keycode == KEY_UP)
	{
		data->current_word--;
		if (data->current_word < 0)
			data->current_word = data->word_count - 1;
	}
}

static void			handle_left_right(t_data *data, int keycode)
{
	int				new_current_word;
	int				position_from_top;

	position_from_top = data->current_word % data->height;
	if (keycode == KEY_LEFT)
	{
		new_current_word = data->current_word - data->height;
		if (new_current_word < 0)
			data->current_word = new_current_word
			+ (data->word_count / data->height) * data->height
			+ (position_from_top < data->height
				- data->word_count % data->height) * data->height;
		else
			data->current_word = new_current_word;
		if (data->current_word >= data->word_count)
			data->current_word -= data->height;
	}
	else if (keycode == KEY_RIGHT)
	{
		new_current_word = data->current_word + data->height;
		if (new_current_word >= data->word_count)
			data->current_word = position_from_top;
		else
			data->current_word = new_current_word;
	}
}

int					loop_helper(unsigned long keycode, t_data *data, \
															int should_refresh)
{
	if (keycode == KEY_BACKSPACE || keycode == KEY_DELETE)
		remove_selected(data);
	else if (keycode == KEY_SPACE)
		select_deselect(data);
	else if (keycode == KEY_ENTER)
		return_highlighted_words(data);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		handle_left_right(data, keycode);
	else if (keycode == KEY_DOWN || keycode == KEY_UP)
		handle_up_down(data, keycode);
	else if (keycode == KEY_ESCAPE || keycode == 'q')
		abort_exit(0);
	else
		should_refresh = 0;
	return (should_refresh);
}

void				input_loop(void)
{
	unsigned long	keycode;
	t_data			*data;
	int				should_refresh;

	data = get_set_data(NULL);
	keycode = 0;
	while (read(0, &keycode, 6) != 0)
	{
		should_refresh = 1;
		should_refresh = loop_helper(keycode, data, should_refresh);
		if (should_refresh)
			refresh_screen(0);
		keycode = 0;
	}
}
