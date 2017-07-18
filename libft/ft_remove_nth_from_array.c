/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_nth_from_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:45:46 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 08:45:51 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/core/ft_select.h"

void				ft_remove_nth_from_array(int nth, void *array
		, size_t width, int length)
{
	char			*to_remove;

	to_remove = (((char*)array) + nth * width);
	ft_memmove((void*)to_remove, (void*)(to_remove + width)
			, (length - nth - 1) * width);
}
