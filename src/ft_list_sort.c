/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:43:25 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/06 18:44:32 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	t_list	*tmp_list;
	void	*tmp_data;

	i = 1;
	if (!(begin_list && *begin_list))
		return ;
	while (i != 0)
	{
		tmp_list = *begin_list;
		i = 0;
		while (tmp_list->next)
		{
			if (cmp(tmp_list->content, tmp_list->next->content) > 0)
			{
				tmp_data = tmp_list->content;
				tmp_list->content = tmp_list->next->content;
				tmp_list->next->content = tmp_data;
				i++;
			}
			tmp_list = tmp_list->next;
		}
	}
}
