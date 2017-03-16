/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:45:49 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/16 16:53:19 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <time.h>

void wait_for (unsigned int secs)
{
	unsigned int ret_time;
	ret_time = time(0) + secs;   // Get finishing time.
	while (time(0) < ret_time);               // Loop until it arrives.
}

int			main(int argc, char **argv, char **environ)
{
	(void)argc;
	(void)argv;
	(void)environ;
	int i;

	i = 1;
	ft_putstr("\033[?1049h\033[H");
	while (argv[i] != NULL)
	{
		ft_printf("%s ", argv[i]);
		i++;
	}
	wait_for(3);
	ft_putstr("\033[?1049l");
	return (0);
}
