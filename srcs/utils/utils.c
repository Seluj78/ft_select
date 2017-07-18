/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:45:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 09:45:42 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

int			get_longest_word_length(t_data *data)
{
	int				longest_word_length;
	int				current_length;
	int				i;

	longest_word_length = 0;
	i = 0;
	while (i < data->word_count)
	{
		current_length = ft_strlen((char*)data->words[i]);
		if (current_length > longest_word_length)
			longest_word_length = current_length;
		i++;
	}
	return (longest_word_length);
}

/*
** hack to store the environment somewhere (globals are not allowed)
** if argument is non-NULL, sets env
** always returns the current env
*/

t_data		*get_set_data(t_data *new_data)
{
	static t_data	*stored_data = NULL;

	if (new_data)
		stored_data = new_data;
	return (stored_data);
}
