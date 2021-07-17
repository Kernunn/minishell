/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command_into_arguments.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:56:43 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/12 17:56:05 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_command.h"
#include "split_command_into_arguments_extra.h"
#include <stdlib.h>

static char	*union_token_in_str(t_token **tokens, int count)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (!(tmp = ft_strdup("")))
		exit(1);
	while (i < count)
	{
		tmp2 = ft_strjoin(tmp, tokens[i]->str);
		free(tmp);
		tmp = tmp2;
		i++;
	}
	return (tmp2);
}

static void	token_to_file_name(t_simple_command *command)
{
	t_redirection	*red;
	t_list			*tmp;

	tmp = command->redirection_output;
	while (tmp)
	{
		red = tmp->content;
		red->file_name = union_token_in_str(red->name_file,
				red->number_of_token_in_name_file);
		tmp = tmp->next;
	}
	tmp = command->redirection_input;
	while (tmp)
	{
		red = tmp->content;
		if (red->type_of_redirection != LESSLESS)
			red->file_name = union_token_in_str(red->name_file,
											red->number_of_token_in_name_file);
		tmp = tmp->next;
	}
}

static void	new_argument(t_simple_command *simple_command,
		int i, char ***argv, int *space)
{
	if (simple_command->tokens[i])
	{
		if ((simple_command->tokens)[i]->type == SPACE)
			*space = 1;
		else
		{
			if (*space)
				add_new_arguments(argv, (simple_command->tokens)[i], space);
			else
				join_to_old_arg(argv, (simple_command->tokens)[i], space);
		}
	}
}

static void	token_to_argv(t_simple_command *simple_command)
{
	int		i;
	int		space;
	char	**argv;

	i = 0;
	space = 1;
	argv = NULL;
	while (i < simple_command->number_of_token)
	{
		new_argument(simple_command, i, &argv, &space);
		i++;
	}
	simple_command->argv = argv;
	token_to_file_name(simple_command);
}

void		split_command_into_arguments(t_list *commands)
{
	int					i;
	t_command			*tmp_command;

	i = 0;
	while (commands)
	{
		tmp_command = ((t_elem_of_list*)(commands->content))->command;
		while (i < tmp_command->number_of_simple_commands)
		{
			token_to_argv(tmp_command->simple_commands[i]);
			i++;
		}
		commands = commands->next;
	}
}
