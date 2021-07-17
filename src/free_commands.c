#include <stdlib.h>
#include "t_command.h"
#include <unistd.h>
#include "libft.h"

static void	free_token(t_token *token)
{
	if (token)
		free(token->str);
	free(token);
}

static void	free_redirection(t_list *lst)
{
	t_list			*tmp;
	int				i;
	t_redirection	*red;

	tmp = lst;
	while (tmp)
	{
		red = tmp->content;
		i = 0;
		if (red->type_of_redirection == LESSLESS)
			unlink(red->file_name);
		free(red->file_name);
		while (i < red->number_of_token_in_name_file)
			free_token(red->name_file[i++]);
		free(red->name_file);
		tmp = tmp->next;
	}
	ft_lstclear(&lst, free);
}

static void	free_simple_command(t_simple_command *simple_command)
{
	int		i;

	i = 0;
	while (i < simple_command->number_of_token)
		free_token(simple_command->tokens[i++]);
	free(simple_command->tokens);
	i = 0;
	while (simple_command->argv && simple_command->argv[i])
		free(simple_command->argv[i++]);
	free(simple_command->argv);
	if (simple_command->redirection_output)
		free_redirection(simple_command->redirection_output);
	if (simple_command->redirection_input)
		free_redirection(simple_command->redirection_input);
}

static void	free_command(t_command *command)
{
	int i;

	i = 0;
	while (i < command->number_of_simple_commands)
	{
		free_simple_command(command->simple_commands[i]);
		free(command->simple_commands[i]);
		i++;
	}
	free(command->simple_commands);
	i = 0;
	while (i < command->number_of_token)
	{
		free_token(command->tokens[i]);
		i++;
	}
	free(command->tokens);
	free(command->pid);
	free(command);
}

void		free_commands(t_list **command)
{
	int		i;
	t_list	*tmp_list;

	if (!command)
		return ;
	i = 0;
	while (*(command + i) != NULL)
	{
		tmp_list = *(command + i);
		while (tmp_list)
		{
			free_command(((t_elem_of_list*)(tmp_list)->content)->command);
			tmp_list = tmp_list->next;
		}
		ft_lstclear(command + i, free);
		i++;
	}
	free(command);
}
