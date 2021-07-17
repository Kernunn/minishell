/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:40:48 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/06 18:42:44 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *cur;
	t_list *prev;
	t_list *next;

	if (!begin_list)
		return ;
	cur = *begin_list;
	prev = NULL;
	while (cur)
	{
		next = cur->next;
		if (cmp(cur->content, data_ref) == 0)
		{
			if (prev)
				prev->next = next;
			else
				*begin_list = next;
			ft_lstdelone(cur, free);
		}
		else
			prev = cur;
		cur = next;
	}
}
