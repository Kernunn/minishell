/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:02:30 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/10 16:12:40 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef DOUBLE_LIST_BONUS_H
#	define DOUBLE_LIST_BONUS_H

#include "struct_bonus.h"

typedef struct	s_double_list
{
	t_buf					*content;
	struct s_double_list	*prev;
	struct s_double_list	*next;
}				t_double_list;

t_double_list	*create_elem_of_dlist(void);
void			ft_dlist_pushback(t_double_list **begin, t_double_list *cur);
t_double_list	*ft_last_dlist(t_double_list *lst);

#	endif
