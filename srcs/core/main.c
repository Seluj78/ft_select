/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 13:39:17 by tfleming          #+#    #+#             */
/*   Updated: 2015/05/15 20:02:39 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_select.h"



static void			restart(int signum)
{
	t_data	*data;

	(void)signum;
	data = get_set_data(NULL);
	setup_terminal(data);
	set_signals(&restart);
	refresh_screen(0);
}

int					main(int argc, char **argv)
{
	t_data	*env;

	if (argc < 2)
	{
		ft_putendl_fd("Usage: ft_select [parameters]", 2);
		exit(1);
	}
	env = malloc(sizeof(t_data));
	setup_environment(env, argc, argv);
	get_set_data(env);
	set_signals(&restart);
	refresh_screen(0);
	input_loop();
	return (0);
}
