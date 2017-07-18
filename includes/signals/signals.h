/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:43:07 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 08:43:10 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

# include <signal.h>
# include "../core/ft_select.h"
# include "../core/exit.h"
# include "../display/display.h"

void			set_signals(void (*restart_function)(int));

#endif
