//
// Created by seluj78 on 7/17/17.
//

#ifndef FT_SELECT_DISPLAY_H_H
# define FT_SELECT_DISPLAY_H_H

# include "../core/data.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include "../../libft/includes/libft.h"
# include "../utils/utils.h"
# include "../core/exit.h"

void				clear_screen_from_text(t_data *data);
void				refresh_screen(int signum);
void				print_words(t_data *data);

#endif
