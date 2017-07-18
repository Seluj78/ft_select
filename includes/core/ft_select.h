/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:42:37 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 08:42:40 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
** Allowed functions:
** isatty
** ttyname
** ttyslot
** ioctl (gets struct winsize, column width and column height)
** getenv
** tcsetattr
** tcgetattr
** tgetent (do this before doing the other t* commands -- sets the TERM)
** tgetflag
** tgetnum
** tgetstr (gets string to do termcaps command)
** tgoto
** tputs
** open
** close
** write
** malloc
** free
** read
** exit
** signal
*/

/*
** termios.h :: tc[get/set]attr
** term.h :: tgetent, tgetstr, etc.
** ioctl.h :: ioctl
*/

# include "../../libft/includes/libft.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include "../signals/signals.h"
# include "data.h"
# include "init.h"

void				input_loop(void);
void				return_highlighted_words(t_data *data);

#endif
