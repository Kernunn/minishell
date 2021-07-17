/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:34:28 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/10 16:08:59 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef STRUCT_BONUS_H
#	define STRUCT_BONUS_H

typedef struct	s_buf
{
	char	*buffer;
	int		available_char;
	int		length;
	int		cur_pos;
	char	*history_str;
}				t_buf;

t_buf			*new_buffer(void);

#	endif
