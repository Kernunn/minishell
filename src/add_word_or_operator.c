/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word_or_operator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:13:27 by gmorros           #+#    #+#             */
/*   Updated: 2020/11/29 11:29:26 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token.h"
#include "libft.h"
#include <stdlib.h>
#include "add_word_or_operator_extra.h"

extern int g_errno;

void		add_word(char **str, t_list **list)
{
	char	*new_str;

	new_str = NULL;
	while (1)
	{
		if (!is_metacharacter(**str) && **str != '\0')
			new_str = add_char_in_str(new_str, **str);
		else if (**str == '\\')
		{
			if (*(*str + 1) != '\0')
			{
				(*str)++;
				new_str = add_char_in_str(new_str, **str);
			}
		}
		else
		{
			add_word_in_list(&new_str, list, 0);
			break ;
		}
		(*str)++;
	}
}

void		add_word_in_single_quotes(char **str, t_list **list)
{
	size_t	i;
	t_token	*token;

	i = 1;
	while ((*str)[i] != '\'' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\0')
	{
		g_errno = 1;
		return ;
	}
	token = malloc(sizeof(t_token));
	if (!token)
		exit(1);
	if (!(token->str = ft_substr(*str, 1, i - 1)))
		exit(1);
	token->type = WORD_IN_SINGLE_QUOTES;
	ft_lstadd_back(list, ft_lstnew(token));
	*str = *str + i + 1;
}

static void	check_second_quotes(char **str)
{
	if (**str == '\"')
		(*str)++;
	else
		g_errno = 2;
}

void		add_word_in_double_quotes(char **str, t_list **list)
{
	char	*new_str;

	new_str = NULL;
	(*str)++;
	while (1)
	{
		if (**str != '\0' && **str != '\"' && **str != '\\' && **str != '$')
			new_str = add_char_in_str(new_str, **str);
		else if (**str == '\\')
			add_backslash_in_quotes(&new_str, str);
		else
		{
			add_word_in_list(&new_str, list, 1);
			if (**str == '$')
				add_parameter(str, list, 1);
			else
			{
				check_second_quotes(str);
				break ;
			}
		}
		(*str)++;
	}
	add_word_in_list(&new_str, list, 1);
}
