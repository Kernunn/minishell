/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:33:20 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/06 18:33:41 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_LIST_REMOVE_IF_H
#	define FT_LIST_REMOVE_IF_H

#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)());

#	endif
