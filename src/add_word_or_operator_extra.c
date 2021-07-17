/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word_or_operator_extra.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:23:32 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/10 20:09:32 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_token.h"
#include <stdlib.h>
#include "add_word_or_operator_extra.h"

char		*add_char_in_str(char *old_str, char c)
{
	size_t	len;
	char	*new_str;

	len = old_str == NULL ? 0 : ft_strlen(old_str);
	if (!(new_str = ft_calloc((len + 2), sizeof(char))))
		exit(1);
	ft_strlcpy(new_str, old_str, len + 2);
	new_str[len] = c;
	free(old_str);
	return (new_str);
}

void		add_word_in_list(char **str, t_list **list, int quotes)
{
	t_token	*token;

	if (*str == NULL)
		if (!(*str = ft_strdup("")))
			exit(1);
	if (!(token = malloc(sizeof(t_token))))
		exit(1);
	token->str = *str;
	*str = NULL;
	token->type = WORD + quotes;
	ft_lstadd_back(list, ft_lstnew(token));
}

static int	check(char *str, int i)
{
	if (str[i] == '\0' || str[i] == '=')
		return (0);
	if (is_metacharacter(str[i]))
		return (0);
	if (ft_isdigit(str[i]) && i == 1)
		return (0);
	if (str[i] == '?')
		return (0);
	return (1);
}

void		add_parameter(char **str, t_list **list, int quotes)
{
	size_t	i;
	t_token *token;

	i = 1;
	while (check((*str), i))
		i++;
	if ((ft_isdigit((*str)[i]) || (*str)[i] == '?') && i == 1)
		i++;
	if (!(token = malloc(sizeof(t_token))))
		exit(1);
	if (i == 1)
	{
		token->type = WORD + quotes;
		token->str = ft_strdup("$");
	}
	else
	{
		token->type = VAR + quotes;
		token->str = ft_substr(*str + 1, 0, i - 1);
	}
	ft_lstadd_back(list, ft_lstnew(token));
	*str = *str + i - 1;
}

void		add_backslash_in_quotes(char **new_str, char **str)
{
	if (*(*str + 1) == '\\' || *(*str + 1) == '$' || *(*str + 1) == '\"')
		(*str)++;
	*new_str = add_char_in_str(*new_str, **str);
}
