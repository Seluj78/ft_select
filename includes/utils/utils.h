/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:43:19 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 08:43:50 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../core/data.h"
# include "../../libft/includes/libft.h"

int			get_longest_word_length(t_data *data);

/*
** hack to store the data somewhere (globals are not allowed)
** if argument is non-NULL, sets data
** always returns the current data
*/

t_data		*get_set_data(t_data *new_data);

#endif
