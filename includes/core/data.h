//
// Created by seluj78 on 7/17/17.
//

#ifndef FT_DATA_H
#define FT_DATA_H

# define KEY_ESCAPE 0x1B
# define KEY_SPACE 0x20
# define KEY_UP 0x415B1B
# define KEY_DOWN 0x425B1B
# define KEY_RIGHT 0x435B1B
# define KEY_LEFT 0x445B1B
# define KEY_ENTER 0xA
# define KEY_BACKSPACE 0x7F
# define KEY_DELETE 0x7E335B1B

/*
** width, height: size of terminal currently
** words: the strings
** words_count: number of strings
** highlighted_p: is highlighted_p[x] = if words[x] is highlighted
** current_argument: where the cursor is
** term: terminal stuff (bleh)
*/

typedef struct		s_data
{
	int				width;
	int				height;
	char			**words;
	int				word_count;
	int				*highlighted_p;
	int				current_word;
	int				single_column_width;
	struct termios	*term;
}					t_data;

#endif
