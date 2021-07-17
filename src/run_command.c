/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:08:32 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/12 17:54:37 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_command.h"
#include "run_built_in.h"
#include "run_external.h"
#include <unistd.h>
#include "run_command_extra.h"
#include "stdlib.h"
#include "signal.h"
#include "built_in_function.h"
#include "sys/wait.h"

extern int g_status;

static void	status_handling(void)
{
	if (WIFEXITED(g_status))
		g_status = WEXITSTATUS(g_status);
	else
	{
		g_status = WTERMSIG(g_status);
		if (g_status == 2)
			g_status = 130;
		else if (g_status == 3)
		{
			g_status = 131;
			write(2, "^\\Quit (core dumped)\n", 21);
		}
	}
}

static void	execute_one_built_in(t_command *command, int tmpfd[2])
{
	if (command->simple_commands[0]->redirection_output)
		redirection_output(command->simple_commands[0]->redirection_output,
				NULL);
	if (command->simple_commands[0]->redirection_input)
		redirection_input(command->simple_commands[0]->redirection_input, NULL);
	ft_built_in_function(command->simple_commands[0]->argv, 0);
	save_and_restore(tmpfd, 1, NULL);
	status_handling();
}

static void	execute_in_fork(t_command *command, int i,
		int lpipe[2], int rpipe[2])
{
	if (command->simple_commands[i]->redirection_input || i != 0)
		redirection_input(command->simple_commands[i]->redirection_input,
				lpipe);
	if (command->simple_commands[i]->redirection_output ||
	i != command->number_of_simple_commands - 1)
		redirection_output(command->simple_commands[i]->redirection_output,
				rpipe);
	signal(SIGINT, (void (*)())0);
	signal(SIGQUIT, (void (*)())0);
	if (command->simple_commands[i]->argv)
	{
		if (is_built_in(command->simple_commands[i]->argv[0]))
			ft_built_in_function(command->simple_commands[i]->argv, 1);
		else
			executing_external((command->simple_commands)[i]);
	}
}

static void	create_fork(t_command *command, int i, int lpipe[2], int rpipe[2])
{
	pipe(rpipe);
	if ((command->pid[i] = fork()) < 0)
		exit(1);
	if (command->pid[i] == 0)
		execute_in_fork(command, i, lpipe, rpipe);
	if (i != 0)
	{
		close(lpipe[0]);
		close(lpipe[1]);
	}
	if (i != command->number_of_simple_commands - 1)
	{
		lpipe[0] = rpipe[0];
		lpipe[1] = rpipe[1];
	}
}

void		run(t_command *command)
{
	int i;
	int tmpfd[2];
	int lpipe[2];
	int rpipe[2];

	save_and_restore(tmpfd, 0, NULL);
	if (command->number_of_simple_commands == 1
	&& is_built_in(((command->simple_commands)[0]->argv)[0]))
		return (execute_one_built_in(command, tmpfd));
	if (!(command->pid = malloc(sizeof(int)
					* command->number_of_simple_commands)))
		exit(1);
	i = 0;
	while (i < command->number_of_simple_commands)
		create_fork(command, i++, lpipe, rpipe);
	i = 0;
	while (i < command->number_of_simple_commands)
	{
		waitpid(command->pid[i++], &g_status, 0);
		status_handling();
	}
	save_and_restore(tmpfd, 1, rpipe);
}
