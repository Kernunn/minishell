/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:16:00 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/12 17:53:51 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_command.h"
#include "parameter_expansion.h"

static void	expansion_redirection_file(t_simple_command *command)
{
	t_list			*tmp;
	int				i;
	t_redirection	*tmp_red;

	tmp = command->redirection_output;
	while (tmp)
	{
		i = 0;
		tmp_red = tmp->content;
		while (i < tmp_red->number_of_token_in_name_file)
			parameter_expansion(tmp_red->name_file[i++]);
		tmp = tmp->next;
	}
	tmp = command->redirection_input;
	while (tmp)
	{
		i = 0;
		tmp_red = tmp->content;
		while (i < tmp_red->number_of_token_in_name_file)
			parameter_expansion(tmp_red->name_file[i++]);
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
			parameter_expansion(simple_command->tokens[i]);
		i++;
	}
	expansion_redirection_file(simple_command);
}

void		shell_expansion(t_list *commands)
{
	int					i;
	t_command			*tmp_command;

	i = 0;
	while (commands)
	{
		tmp_command = ((t_elem_of_list*)(commands->content))->command;
		while (i < tmp_command->number_of_simple_commands)
		{
			expansion(tmp_command->simple_commands[i]);
			i++;
		}
		commands = commands->next;
	}
}
