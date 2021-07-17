/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:06:18 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/10 18:58:16 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_command.h"
#include "unistd.h"
#include "libft.h"
#include "free_commands.h"
#include "ft_error.h"
#include "run_command.h"
#include <signal.h>
#include "t_command.h"
#include "shell_expansion.h"
#include "wildcard_expansion.h"
#include "split_command_into_arguments.h"
#include "copy_env.h"

int		g_errno = 0;
int		g_status = 0;
int		g_no_promt = 0;
int		g_sigint = 0;
char	**g_env = NULL;

void	type_promt(void)
{
	if (!g_no_promt)
		write(2, "$ ", 2);
	g_no_promt = 0;
}

void	handler_signal(int type)
{
	if (type == SIGINT)
	{
		write(2, "\n$ ", 3);
		g_status = 130;
		g_no_promt = 1;
		g_sigint = 1;
	}
	if (type == SIGQUIT)
	{
		write(2, "\b\b  \b\b", 6);
	}
}

t_list	**get_command(void)
{
	t_list	**commands;

	commands = parsing_command();
	g_no_promt = 0;
	if (g_errno)
	{
		free_commands(commands);
		commands = NULL;
		print_error();
		g_status = 2;
	}
	return (commands);
}

void	run_command(t_list **commands)
{
	t_list			*tmp_list;
	t_elem_of_list	*command;

	while (*commands != NULL && !g_errno)
	{
		tmp_list = *commands;
		while (tmp_list && !g_errno)
		{
			shell_expansion(tmp_list);
			wildcard_expansion(tmp_list);
			if (g_errno)
				break ;
			split_command_into_arguments(tmp_list);
			command = tmp_list->content;
			run(command->command);
			if (command->type == AND && g_status)
				break ;
			if (command->type == OR && !g_status)
				break ;
			tmp_list = tmp_list->next;
		}
		commands++;
	}
	g_errno = 0;
}

int		main(int argc, char **argv, char **env)
{
	t_list		**commands;

	ft_copy_env(argc, argv, env);
	signal(SIGQUIT, handler_signal);
	signal(SIGINT, handler_signal);
	while (1)
	{
		type_promt();
		commands = get_command();
		if (!commands)
			continue ;
		run_command(commands);
		free_commands(commands);
	}
	return (0);
}
