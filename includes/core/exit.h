//
// Created by seluj78 on 7/17/17.
//

#ifndef FT_SELECT_EXIT_H
# define FT_SELECT_EXIT_H

# include "../core/data.h"
# include "../utils/utils.h"
# include "../display/display.h"
# include <termios.h>
# include <term.h>
# include <bits/signum.h>
# include <signal.h>
# include <sys/ioctl.h>


void				abort_no_exit(int signum);
void				abort_exit(int signum);

#endif
