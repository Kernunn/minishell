#include <unistd.h>
#include "libft.h"

extern int g_status;
extern char **g_env;

static int	ft_miss_n(char **argv)
{
	int i;

	i = 2;
	if (argv && argv[0] && argv[0][0] == '-' && argv[0][1] == 'n')
	{
		while (argv[0][i] == 'n')
			i++;
		if (argv[0][i] == '\0')
			return (1);
	}
	return (0);
}

void		ft_echo(char **argv)
{
	int newline;

	newline = 1;
	if ((*argv) && (!(ft_strncmp(argv[0], "-n", 2))))
	{
		if (ft_miss_n(argv))
		{
			while (ft_miss_n(argv))
				argv++;
			newline = 0;
		}
	}
	while (*argv)
	{
		write(1, *argv, ft_strlen(*argv));
		argv++;
		if (*argv)
			write(1, " ", 1);
	}
	if (newline)
		write(1, "\n", 1);
	g_status = 0;
}
