/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_hidden.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:52:51 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/06 18:53:33 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	remove_hidden(char *content, char *match_str)
{
	char	*ptr_slash;

	if (match_str[0] == '.')
		return (1);
	ptr_slash = ft_strrchr(content, '/');
	if (ptr_slash == NULL)
	{
		if (content[0] == '.')
			return (0);
		return (1);
	}
	else
	{
		if (*(ptr_slash + 1) == '.')
			return (0);
		return (1);
	}
}
