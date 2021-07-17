/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:59:51 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/10 16:10:22 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MOVE_BONUS_H
#	define MOVE_BONUS_H

#include "struct_bonus.h"

void	move(t_buf *buf, char ch);
void	home_end(t_buf *buf, char ch);
void	ctrl_left(t_buf *buf);
void	ctrl_right(t_buf *buf);

#	endif
