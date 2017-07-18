/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:42:09 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 10:23:07 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "../core/data.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include "../../libft/includes/libft.h"
# include "../utils/utils.h"
# include "../core/exit.h"

void				remove_selected(t_data *data);
void				cl_screen(t_data *data);
void				refresh_screen(int signum);
void				print_words(t_data *data);

#endif
