#include "t_token.h"
#include "t_command.h"
#include <stdlib.h>

static void	move_array_of_token(t_token **dest, t_token **source, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
}

void		insert_token(t_token *argument, t_command *command)
{
	t_token	**new_array;

	if (command->tokens == NULL)
	{
		command->tokens = malloc(4 * sizeof(t_token*));
		if (!command->tokens)
			exit(1);
		command->number_of_available_token = 4;
	}
	if (command->number_of_token >= command->number_of_available_token)
	{
		new_array = malloc(2 * command->number_of_available_token
				* sizeof(t_token*));
		move_array_of_token(new_array, command->tokens,
							command->number_of_token);
		free(command->tokens);
		command->tokens = new_array;
		command->number_of_available_token *= 2;
	}
	(command->tokens)[command->number_of_token] = argument;
	command->number_of_token += 1;
}

void		insert_token_in_simple_command(t_token *argument,
		t_simple_command *command)
{
	t_token **new_array;

	if (command->tokens == NULL)
	{
		command->tokens = malloc(4 * sizeof(t_token*));
		if (!command->tokens)
			exit(1);
		command->number_of_available_token = 4;
	}
	if (command->number_of_token >= command->number_of_available_token)
	{
		new_array = malloc(2 * command->number_of_available_token
				* sizeof(t_token*));
		move_array_of_token(new_array, command->tokens,
							command->number_of_token);
		free(command->tokens);
		command->tokens = new_array;
		command->number_of_available_token *= 2;
	}
	(command->tokens)[command->number_of_token] = argument;
	command->number_of_token += 1;
}

static void	move_array_of_simple_commands(t_simple_command **dest,
		t_simple_command **source, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
}

void		insert_simple_command(t_simple_command *simple_command,
		t_command *command)
{
	t_simple_command **new_array;

	if (command->simple_commands == NULL)
	{
		command->simple_commands = malloc(4 * sizeof(t_simple_command*));
		if (!command->simple_commands)
			exit(1);
		command->number_of_available_simple_commands = 4;
	}
	if (command->number_of_simple_commands
		>= command->number_of_available_simple_commands)
	{
		new_array = malloc(2 * command->number_of_available_simple_commands
				* sizeof(t_simple_command*));
		move_array_of_simple_commands(new_array, command->simple_commands,
				command->number_of_simple_commands);
		free(command->simple_commands);
		command->simple_commands = new_array;
		command->number_of_available_simple_commands *= 2;
	}
	(command->simple_commands)[command->number_of_simple_commands] =
			simple_command;
	command->number_of_simple_commands += 1;
}
