# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlasne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 10:25:59 by jlasne            #+#    #+#              #
#    Updated: 2017/03/16 12:50:13 by jlasne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC =	main.c\

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT =	libft/libft.a

CC = gcc

FLAGS = -g3 -Wall -Wextra -Werror #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o : $(SRC_PATH)/%.c
		    $(CC) -o $@ -c $< $(FLAGS)

$(LIBFT):
		make -C ./libft/

clean:
		rm -rf $(OBJ)
			make clean -C ./libft/

fclean: clean
		rm -rf $(NAME)
			make fclean -C ./libft/

re: fclean all

test:
	make re

.PHONY : all re clean fclean test
