#include "libft.h"
#include "t_command.h"
#include <stdlib.h>
#include <unistd.h>

extern int g_errno;
extern int g_status;

void	check_ambiguous_redirection(char *str)
{
	char	**array;
	int		count;

	array = ft_split(str, ' ');
	if (!array)
		exit(1);
	count = 0;
	while (array[count])
	{
		free(array[count]);
		count++;
	}
	free(array);
	if (count > 1)
	{
		g_errno = 12;
		g_status = 1;
		write(2, "bash: ambiguous redirect\n", 25);
	}
}

int		check_type(t_simple_command *simple_command, int i)
{
	int		answer;

	answer = 0;
	if (i == 0)
		answer += 1;
	else
	{
		if (simple_command->tokens[i - 1]
			&& simple_command->tokens[i - 1]->type == SPACE)
			answer += 1;
	}
	if (i == simple_command->number_of_token - 1)
		answer += 1;
	else
	{
		if (simple_command->tokens[i + 1]
			&& simple_command->tokens[i + 1]->type == SPACE)
			answer += 1;
	}
	if (simple_command->tokens[i]->type == WORD
		|| simple_command->tokens[i]->type == VAR)
		answer += 1;
	return (answer == 3 ? 1 : 0);
}
