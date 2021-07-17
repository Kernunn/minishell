/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:15:05 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/11 21:43:18 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "insert_delete_on_screen_bonus.h"
#include "struct_bonus.h"
#include <stdlib.h>

void	insert_ch_in_str(t_buf *buf, char ch)
{
	if (buf->length == 0)
	{
		buf->buffer = ft_calloc(80, sizeof(char));
		if (buf->buffer == NULL)
			exit(1);
		buf->available_char = 80;
	}
	if (buf->length + 1 >= buf->available_char)
	{
		buf->buffer = realloc(buf->buffer, buf->length * 2);
		if (buf->buffer == NULL)
			exit(1);
		buf->available_char *= 2;
	}
	ft_memmove(buf->buffer + buf->cur_pos + 1, buf->buffer + buf->cur_pos,
			buf->length - buf->cur_pos + 1);
	buf->buffer[buf->cur_pos] = ch;
	buf->length += 1;
	buf->cur_pos += 1;
}

void	insert_char(t_buf *buf, char ch)
{
	insert_ch_in_str(buf, ch);
	insert_ch_on_screen(ch);
}
