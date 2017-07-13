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

/*
int     voir_touche()
{
	char     buff[10];

	while (1)
	{
		ft_bzero(buff, sizeof(buff));
		read(0, buff, 10);
		if (buff[0] == 27 && buff[1] == 91 && buff [2] == 68) //TODO : Check que buff[3] == 0
			ft_printf("LEFT ARROW\n");
		if (buff[0] == 27 && buff[1] == 91 && buff [2] == 67)
			ft_printf("RIGHT ARROW\n");
		if (buff[0] == 27 && buff[1] == 91 && buff [2] == 65)
			ft_printf("UP ARROW\n");
		if (buff[0] == 27 && buff[1] == 91 && buff [2] == 66)
			ft_printf("DOWN ARROW\n");
		if (buff[0] == 32)
			ft_printf("SPACE\n");
		//ft_printf("is:[%d][%d][%d][%d][%d][%d][%d][%d][%d][%d]\n", buff[0], buff[1], buff[2], buff[3], buff[4], buff[5], buff[6], buff[7], buff[8], buff[9]);
	}
}

int     main(int argc, char **argv)
{

	i = 1;
	ft_printf("\n");
	while (argv[i] != NULL)
	{
		ft_printf("%s\t", argv[i]);
		i++;
	}

	ft_printf("\n");
	voir_touche();
	return (0);
}
 */

struct termios canonical_mode(struct termios term)
{
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	return (term);
}

int main(int argc, char **argv)
{
	char *term_name;
	struct termios term;

	(void)argc;
	(void)argv;
	if ((term_name = getenv("TERM")) == NULL)
	{
		ft_putendl_fd("ft_select: Error, TERM environment variable not set.", 2);
		return (-1);
	}
	if (tgetent(NULL, term_name) == -1)
	{
		ft_putendl_fd("ft_select: Error, tgetent was unable to find the term you're using.", 2);
		return (-1);
	}
	if (tcgetattr(0, &term) == -1)
	{
		ft_putendl_fd("ft_select: Error, tcgetattr was unable to fetch your terminal attributes.", 2);
		return (-1);
	}
	term = canonical_mode(term);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
	{
		ft_putendl_fd("ft_select: Error, tcsetattr was unable to set the modified terminal attributes.", 2);
		return (-1);
	}
	return (0);
}