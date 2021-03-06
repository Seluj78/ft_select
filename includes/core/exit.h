/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:42:02 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 08:42:15 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_EXIT_H
# define FT_SELECT_EXIT_H

# include "../core/data.h"
# include "../utils/utils.h"
# include "../display/display.h"
# include <termios.h>
# include <term.h>
# include <sys/signal.h>
# include <sys/ioctl.h>

void				abort_no_exit(int signum);
void				abort_exit(int signum);

#endif
