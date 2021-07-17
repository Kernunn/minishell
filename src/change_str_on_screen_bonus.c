/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_str_on_screen_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:04:05 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/11 20:35:29 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insert_delete_on_screen_bonus.h"
#include "libft.h"

void	change_str_on_screen(int len_str, char *str_next)
{
	if (len_str)
		delete_line_on_screen(len_str);
	if (str_next)
		ft_putstr_fd(str_next, 2);
}
