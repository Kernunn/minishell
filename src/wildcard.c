/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:49:12 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/10 16:16:29 by bbenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wildcard.h"
#include <stdlib.h>

void	wildcard(char **str)
{
	char	*copy_str;
	t_list	**list;

	copy_str = *str;
	if (!(list = malloc(sizeof(t_list*))))
		exit(1);
	*list = NULL;
	*str = expantion_stars(copy_str, list, 0);
	free(list);
	if (ft_strncmp(*str, "", 1) == 0)
	{
		free(*str);
		*str = copy_str;
	}
	else
		free(copy_str);
}
