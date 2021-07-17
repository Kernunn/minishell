/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word_or_operator2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:08:23 by gmorros           #+#    #+#             */
/*   Updated: 2020/11/26 12:38:59 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token.h"
#include "libft.h"
#include <stdlib.h>
#include "add_word_or_operator_extra.h"

void	add_metacharacter(char **str, t_list **list)
{
	t_token *token;

	if (**str == '$')
	{
		(add_parameter(str, list, 0));
		(*str)++;
		return ;
	}
	if (!(token = malloc(sizeof(t_token))))
		exit(1);
	if (**str == '|')
		token->type = pipe_or_or(str);
	else if (**str == ';')
		token->type = COLON;
	else if (**str == '<')
		token->type = less_or_lessless(str);
	else if (**str == '>')
		token->type = great_or_greatgreat(str);
	else if (**str == '&')
		token->type = and_or_word(str, token);
	if (token->type != WORD)
		token->str = NULL;
	ft_lstadd_back(list, ft_lstnew(token));
	(*str)++;
}

void	add_space_or_tab(char **str, t_list **list)
{
	t_token	*token;

	while ((**str == ' ' || **str == '\t') && **str != '\0')
		(*str)++;
	token = malloc(sizeof(t_token));
	if (!token)
		exit(1);
	token->type = SPACE;
	token->str = NULL;
	ft_lstadd_back(list, ft_lstnew(token));
}

void	add_newline(t_list **list)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		exit(1);
	token->type = NEWLINE;
	token->str = NULL;
	ft_lstadd_back(list, ft_lstnew(token));
}
