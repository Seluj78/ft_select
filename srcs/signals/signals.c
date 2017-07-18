/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:45:17 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 09:45:19 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals/signals.h"

void			signal_handler(void (*restart_function)(int))
{
	signal(SIGWINCH, refresh_screen);
	signal(SIGCONT, restart_function);
	signal(SIGTSTP, abort_no_exit);
	signal(SIGINT, abort_exit);
	signal(SIGINT, abort_exit);
	signal(SIGHUP, abort_exit);
	signal(SIGTERM, abort_exit);
	signal(SIGSEGV, abort_exit);
	signal(SIGQUIT, abort_exit);
	signal(SIGFPE, abort_exit);
	signal(SIGALRM, abort_exit);
	signal(SIGKILL, abort_exit);
	signal(SIGABRT, abort_exit);
	signal(SIGUSR1, abort_exit);
	signal(SIGUSR2, abort_exit);
}
