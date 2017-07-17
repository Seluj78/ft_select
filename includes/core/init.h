//
// Created by seluj78 on 7/17/17.
//

#ifndef FT_INIT_H
#define FT_INIT_H

# include "../core/data.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include "../../libft/includes/libft.h"
# include "../utils/utils.h"

void			setup_environment(t_data *data, int argc, char **argv);
void			setup_terminal(t_data *data);

#endif
