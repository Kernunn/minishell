/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word_or_operator_extra2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:37:07 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/10 20:07:36 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token.h"
#include "libft.h"
#include <stdlib.h>

int		is_metacharacter(char c)
{
	if (ft_strchr("><|; \t\\\"\'$&", c))
		return (1);
	return (0);
}

t_type	pipe_or_or(char **str)
{
	if (*(*str + 1) == '|')
	{
		(*str)++;
		return (OR);
	}
	return (PIPE);
}

t_type	less_or_lessless(char **str)
{
	if (*(*str + 1) == '<')
	{
		(*str)++;
		return (LESSLESS);
	}
	return (LESS);
}

t_type	great_or_greatgreat(char **str)
{
	if (*(*str + 1) == '>')
	{
		(*str)++;
		return (GREATGREAT);
	}
	return (GREAT);
}

t_type	and_or_word(char **str, t_token *token)
{
	if (*(*str + 1) == '&')
	{
		(*str)++;
		return (AND);
	}
	token->type = WORD;
	if (!(token->str = ft_strdup("&")))
		exit(1);
	return (WORD);
}
