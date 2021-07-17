/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:52:12 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/11 21:39:48 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "insert_delete_on_screen_bonus.h"
#include "struct_bonus.h"

void	delete(t_buf *buf)
{
	char	ch;

	read(0, &ch, 1);
	if (ch == '~')
	{
		if (buf->length == 0 || buf->cur_pos == buf->length)
			return ;
		ft_memmove(buf->buffer + buf->cur_pos, buf->buffer + buf->cur_pos + 1,
				buf->length - buf->cur_pos + 1);
		buf->length -= 1;
		delete_ch_on_screen();
	}
}

void	backspace(t_buf *buf)
{
	if (buf->length == 0 || buf->cur_pos == 0)
		return ;
	ft_memmove(buf->buffer + buf->cur_pos - 1,
			buf->buffer + buf->cur_pos, buf->length - buf->cur_pos + 1);
	buf->length -= 1;
	buf->cur_pos -= 1;
	backspace_ch_on_screen();
}
