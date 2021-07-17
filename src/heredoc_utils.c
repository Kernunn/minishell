/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:12:45 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/05 18:11:49 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "libft.h"
#include <stdlib.h>

static char	*var_after_dlr(char *str)
{
	int		i;
	char	*meta;
	char	*var;

	i = 1;
	meta = ft_strdup("\n $\'\"\\");
	if (!meta)
		exit(1);
	while ((str)[i] && (!ft_strchr(meta, (str)[i])))
		i++;
	free(meta);
	if (i == 1)
		var = NULL;
	else
		var = ft_substr(str, 1, i - 1);
	return (var);
}

void		ft_add_elem_to_str(char **str, char *add, int num)
{
	char *temp;

	temp = *str;
	if (!temp)
		exit(1);
	add = ft_substr(add, 0, num);
	if (!add)
		exit(1);
	*str = ft_strjoin(temp, add);
	if (!(*str))
		exit(1);
	free(temp);
	free(add);
}

char		*ft_change_str(char *str, int quotes)
{
	char *temp;
	char *res;
	char *var;

	res = ft_strdup("");
	while (*str)
	{
		if ((*str == '\\' && *(str + 1) == '\\' && !quotes)
				|| (*str == '\\' && *(str + 1) == '$' && !quotes))
		{
			ft_add_elem_to_str(&res, str + 1, 1);
			str++;
		}
		else if (*str == '$' && !quotes && (var = var_after_dlr(str)))
		{
			str = str + ft_strlen(var);
			if ((temp = ft_var_of_key(var)) != NULL)
				ft_add_elem_to_str(&res, temp, ft_strlen(temp));
			free(var);
		}
		else
			ft_add_elem_to_str(&res, str, 1);
		str++;
	}
	return (res);
}
