/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:52:22 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/12 17:56:39 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_command.h"
#include "wildcard_first.h"
#include "wildcard_expansion_extra.h"

extern int g_errno;
extern int g_status;

static void	wildcard_token(t_simple_command *simple_command, int i)
{
	if (check_type(simple_command, i))
		if (ft_strchr(simple_command->tokens[i]->str, '*'))
			wildcard(&(simple_command->tokens[i]->str));
}

static void	wild_expansion(t_redirection *red)
{
	if (red->number_of_token_in_name_file == 1)
	{
		if (ft_strchr(red->name_file[0]->str, '*') &&
			red->name_file[0]->type == WORD)
		{
			wildcard(&(red->name_file[0]->str));
			check_ambiguous_redirection(red->name_file[0]->str);
		}
	}
}

static void	wild_expansion_redirection_file(t_simple_command *command)
{
	t_list			*tmp;

	tmp = command->redirection_output;
	while (tmp && !g_errno)
	{
		wild_expansion(tmp->content);
		tmp = tmp->next;
	}
	tmp = command->redirection_input;
	while (tmp && !g_errno)
	{
		wild_expansion(tmp->content);
		tmp = tmp->next;
	}
}

static void	expansion(t_simple_command *simple_command)
{
	int i;

	i = 0;
	while (i < simple_command->number_of_token)
	{
		if (simple_command->tokens[i])
			wildcard_token(simple_command, i);
		i++;
	}
	wild_expansion_redirection_file(simple_command);
}

void		wildcard_expansion(t_list *commands)
{
	int					i;
	t_command			*tmp_command;

	i = 0;
	while (commands && !g_errno)
	{
		tmp_command = ((t_elem_of_list*)(commands->content))->command;
		while (i < tmp_command->number_of_simple_commands && !g_errno)
		{
			expansion(tmp_command->simple_commands[i]);
			i++;
		}
		commands = commands->next;
	}
}
