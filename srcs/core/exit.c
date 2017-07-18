/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:47:25 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 08:47:44 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/exit.h"

void				abort_no_exit(int signum)
{
	t_data	*data;
	char	copy[2];

	(void)signum;
	data = get_set_data(NULL);
	clear_screen_from_text(data);
	data->term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, data->term);
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	if (signum == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		copy[0] = data->term->c_cc[VSUSP];
		copy[1] = 0;
		ioctl(0, TIOCSTI, copy);
	}
}

/*
** ve: return the cursor to normal
** cl: clear the entire screen and position the cursor at the upper
** left corner
** te: undo what is done by the `ti' string. Programs that output the
** ti: string on entry should output this string when they exit
*/

void				abort_exit(int signum)
{
	abort_no_exit(signum);
	exit(0);
}
