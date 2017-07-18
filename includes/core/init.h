/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:42:48 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 08:42:53 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_H
# define FT_INIT_H

# include "../core/data.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include "../../libft/includes/libft.h"
# include "../utils/utils.h"

void			init_data(t_data *data, int argc, char **argv);
void			init_term(t_data *data);

#endif
