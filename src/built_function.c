#include "built_functions.h"
#include <stdlib.h>
#include "libft.h"

extern int g_status;

void	ft_built_in_function(char **arg, int fork)
{
	if (*arg == NULL)
	{
		g_status = 0;
		return ;
	}
	if (!(ft_strncmp(arg[0], "echo", 5)))
		ft_echo(++arg);
	else if (!(ft_strncmp(arg[0], "pwd", 4)))
		ft_pwd();
	else if (!(ft_strncmp(arg[0], "cd", 3)))
		ft_cd(++arg);
	else if (!(ft_strncmp(arg[0], "unset", 6)))
		ft_unset(++arg);
	else if (!(ft_strncmp(arg[0], "export", 7)))
		ft_export(++arg);
	else if (!(ft_strncmp(arg[0], "env", 4)))
		ft_env();
	else
		ft_exit(++arg);
	if (fork)
		exit(g_status);
}
