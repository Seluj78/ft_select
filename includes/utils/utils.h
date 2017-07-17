//
// Created by seluj78 on 7/17/17.
//

#ifndef FT_GET_LONGEST_WORD_LENGTH_H
# define FT_GET_LONGEST_WORD_LENGTH_H

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
