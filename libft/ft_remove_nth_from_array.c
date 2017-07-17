# include "../includes/core/ft_select.h"

void				ft_remove_nth_from_array(int nth, void *array
		, size_t width, int length)
{
	char			*to_remove;

	to_remove = (((char*)array) + nth * width);
	ft_memmove((void*)to_remove, (void*)(to_remove + width)
			, (length - nth - 1) * width);
}