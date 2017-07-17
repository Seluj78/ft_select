NAME	 = ft_select

IDIR	 = includes/
LIDIR    = libft/includes/
LIB	     = libft/libft.a
LNAME	 = libft
LDIR	 = libft

LTCAPS   = -ltermcap

CC	 = clang
CFLAGS	+= -I $(IDIR) -I $(LIDIR)
CFLAGS	+= -Wall -Wextra -Werror

SDIR	 = srcs/

SRCS	 = 			$(SDIR)core/main.c \
                    $(SDIR)core/init.c \
                    $(SDIR)core/exit.c \
          			$(SDIR)utils/utils.c \
                    $(SDIR)signals/signals.c \
           			$(SDIR)core/input_loop.c \
         			$(SDIR)display/refresh_screen.c \
           			$(SDIR)display/clear_screen_from_text.c  \
           			$(SDIR)display/print_words.c \
                	$(SDIR)core/return_highlighted_words.c

OBJS	 = $(SRCS:.c=.o)

RM	 = rm -f

all: $(LIB) $(NAME)

$(LIB):
	cd $(LDIR) && $(MAKE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB) $(LTCAPS)

%.o:$(SRCS)/%.c
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	$(RM) $(OBJS)
	cd $(LDIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd $(LDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re