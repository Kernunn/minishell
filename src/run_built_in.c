#include "libft.h"

int		is_built_in(char *argument)
{
	if (argument == NULL)
		return (1);
	if (!ft_strncmp(argument, "echo", 5))
		return (1);
	if (!ft_strncmp(argument, "cd", 3))
		return (1);
	if (!ft_strncmp(argument, "pwd", 4))
		return (1);
	if (!ft_strncmp(argument, "export", 7))
		return (1);
	if (!ft_strncmp(argument, "unset", 6))
		return (1);
	if (!ft_strncmp(argument, "env", 4))
		return (1);
	if (!ft_strncmp(argument, "exit", 5))
		return (1);
	return (0);
}
