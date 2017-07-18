/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_highlighted_words.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:27:28 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 09:27:35 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "core/ft_select.h"
/*
** ve: return the cursor to normal
** cl: clear the entire screen and position the cursor at the upper left corner
*/

void			return_highlighted_words(t_data *data)
{
	int				i;
	int				print_space_p;

	abort_no_exit(0);
	print_space_p = 0;
	i = 0;
	while (i < data->word_count)
	{
		if (data->highlighted_p[i])
		{
			if (print_space_p)
				ft_putchar(' ');
			ft_putstr(data->words[i]);
			print_space_p = 1;
		}
		i++;
	}
	exit(0);
}

/*
** ve: return the cursor to normal
** cl: clear the entire screen and position the cursor at the upper left corner
*/