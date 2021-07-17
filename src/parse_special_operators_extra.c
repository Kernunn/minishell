/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_special_operators_extra.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:03:52 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/12 17:55:47 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token.h"
#include "t_command.h"
#include <stdlib.h>
#include "ft_error.h"
#include "libft.h"
#include "here_documents.h"
#include "new_struct.h"

extern int g_errno;

static void	move_token(t_simple_command *command, int k, t_redirection *red)
{
	int		i;
	int		count;
	t_token	**tokens;

	count = red->number_of_token_in_name_file;
	tokens = red->name_file;
	i = 0;
	while (i < count)
	{
		tokens[i] = command->tokens[k - count + i];
		command->tokens[k - count + i] = NULL;
		i++;
	}
}

static void	union_near_token(t_simple_command *command, int *k,
		t_redirection *red)
{
	t_type	type;

	red->number_of_token_in_name_file = 0;
	while (*k < command->number_of_token)
	{
		type = command->tokens[*k]->type;
		if (type != WORD && type != WORD_IN_SINGLE_QUOTES && type != VAR &&
		type != WORD_IN_DOUBLE_QUOTES && type != VAR_IN_DOUBLE_QUOTES)
			break ;
		red->number_of_token_in_name_file += 1;
		*k += 1;
	}
	if (!(red->name_file = malloc(sizeof(t_token*) *
			red->number_of_token_in_name_file)))
		exit(1);
	move_token(command, *k, red);
}

void		redirection(t_simple_command *command, int *k,
		t_type type_red, t_type type_arg)
{
	t_redirection *new_red;

	if (type_arg == WORD || type_arg == VAR ||
	type_arg == WORD_IN_DOUBLE_QUOTES || type_arg == VAR_IN_DOUBLE_QUOTES
	|| type_arg == WORD_IN_SINGLE_QUOTES)
	{
		new_red = new_redirection();
		new_red->type_of_redirection = type_red;
		union_near_token(command, k, new_red);
		*k -= 1;
		if (type_red == GREAT || type_red == GREATGREAT)
			ft_lstadd_back(&command->redirection_output, ft_lstnew(new_red));
		else
			ft_lstadd_back(&command->redirection_input, ft_lstnew(new_red));
		return ;
	}
	g_errno = type_of_error(type_arg);
}

static char	*union_token_in_str(t_simple_command *command, int *k, int *quotes)
{
	char	*tmp;
	char	*tmp2;
	t_type	type;

	if (!(tmp = ft_strdup("")))
		exit(1);
	while (*k < command->number_of_token)
	{
		type = command->tokens[*k]->type;
		if (type != WORD && type != WORD_IN_SINGLE_QUOTES && type != VAR &&
			type != WORD_IN_DOUBLE_QUOTES && type != VAR_IN_DOUBLE_QUOTES)
			break ;
		if (type == WORD_IN_DOUBLE_QUOTES || type == WORD_IN_SINGLE_QUOTES
		|| type == VAR_IN_DOUBLE_QUOTES)
			*quotes = 1;
		tmp2 = ft_strjoin(tmp, command->tokens[*k]->str);
		free(tmp);
		free(command->tokens[*k]->str);
		free(command->tokens[*k]);
		command->tokens[*k] = NULL;
		tmp = tmp2;
		*k += 1;
	}
	return (tmp);
}

void		here_document(t_simple_command *command, int *k, t_type type_arg)
{
	char			*word;
	int				quotes;
	t_redirection	*new_red;

	type_arg = command->tokens[*k]->type;
	if (type_arg == WORD || type_arg == VAR || type_arg == WORD_IN_DOUBLE_QUOTES
	|| type_arg == WORD_IN_SINGLE_QUOTES || type_arg == VAR_IN_DOUBLE_QUOTES)
	{
		new_red = new_redirection();
		new_red->type_of_redirection = LESSLESS;
		if (type_arg == WORD || type_arg == VAR)
			quotes = 0;
		else
			quotes = 1;
		word = union_token_in_str(command, k, &quotes);
		new_red->file_name = here_doc(word, quotes);
		ft_lstadd_back(&command->redirection_input, ft_lstnew(new_red));
		free(word);
		*k -= 1;
		return ;
	}
	g_errno = type_of_error(command->tokens[*k]->type);
}
