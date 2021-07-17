#include "libft.h"
#include "t_token.h"
#include "t_command.h"
#include "ft_error.h"

int	check_error_syntax(t_list *list, t_type type)
{
	t_command *command;

	if (!list)
		return (type == COLON ? 3 : 0);
	command = ((t_elem_of_list*)(list->content))->command;
	if (command->number_of_token == 1 && command->tokens[0]->type == SPACE)
		return (3);
	return (0);
}

int	check_error_syntax2(t_command *command, t_type type)
{
	if (command == NULL)
		return (type_of_error(type));
	if (command->number_of_token == 1 && command->tokens[0]->type == SPACE)
		return (type_of_error(type));
	return (0);
}

int	check_syntax_error3(t_simple_command *sim_command)
{
	if (sim_command == NULL)
		return (6);
	if (sim_command->number_of_token == 1 &&
			sim_command->tokens[0]->type == SPACE)
		return (6);
	return (0);
}
