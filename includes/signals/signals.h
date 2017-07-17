//
// Created by seluj78 on 7/17/17.
//

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

# include <signal.h>
# include "../core/ft_select.h"
# include "../core/exit.h"
# include "../display/display.h"

void			set_signals(void (*restart_function)(int));

#endif
