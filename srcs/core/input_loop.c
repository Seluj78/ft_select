/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:51:00 by tfleming          #+#    #+#             */
/*   Updated: 2015/05/15 00:23:16 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** input_loop waits for keypresses on call to read
*/

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

static void			handle_left_right(t_data *env, int keycode)
{
	int				new_current_word;
	int				position_from_top;

	position_from_top = env->current_word % env->height;
	if (keycode == KEY_LEFT)
	{
		new_current_word = env->current_word - env->height;
		if (new_current_word < 0)
			env->current_word = new_current_word
			+ (env->word_count / env->height) * env->height
			+ (position_from_top < env->height
				- env->word_count % env->height) * env->height;
		else
			env->current_word = new_current_word;
		if (env->current_word >= env->word_count)
			env->current_word -= env->height;
	}
	else if (keycode == KEY_RIGHT)
	{
		new_current_word = env->current_word + env->height;
		if (new_current_word >= env->word_count)
			env->current_word = position_from_top;
		else
			env->current_word = new_current_word;
	}
}

static void			remove_selected(t_data *data)
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

void				input_loop(void)
{
	unsigned long	keycode;
	t_data	*env;
	int				should_refresh;

	env = get_set_data(NULL);
	while (keycode = 0, (read(0, &keycode, 6)) != 0)
	{
		should_refresh = 1;
		if (keycode == KEY_BACKSPACE || keycode == KEY_DELETE)
			remove_selected(env);
		else if (keycode == KEY_SPACE)
			select_deselect(env);
		else if (keycode == KEY_ENTER)
			return_highlighted_words(env);
		else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
			handle_left_right(env, keycode);
		else if (keycode == KEY_DOWN || keycode == KEY_UP)
			handle_up_down(env, keycode);
		else if (keycode == KEY_ESCAPE || keycode == 'q')
			abort_exit(0);
		else
			should_refresh = 0;
		if (should_refresh)
			refresh_screen(0);
	}
}
