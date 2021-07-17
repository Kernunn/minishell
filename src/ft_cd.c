#include "ft_env.h"
#include "ft_cd_utils.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_getcwd.h"
#include <errno.h>
#include <string.h>

extern int g_status;
extern char **g_env;

void		ft_cd_old_or_home(char **argv)
{
	char *pwd;
	char *tmp;

	pwd = argv && *argv ? ft_var_of_key("OLDPWD") : ft_var_of_key("HOME");
	tmp = pwd ? ft_strdup(pwd) : NULL;
	if (tmp)
	{
		ft_change_env("OLDPWD", ft_var_of_key("PWD"));
		ft_change_env("PWD", tmp);
		chdir(tmp);
		if (*argv)
		{
			write(1, tmp, ft_strlen(tmp));
			write(1, "\n", 1);
		}
		free(tmp);
	}
	else
	{
		if (*argv)
			write(2, "cd: OLDPWD not set\n", 19);
		else
			write(2, "cd: HOME not set\n", 17);
		g_status = 1;
	}
}

static void	ft_change_env_pwd(char *old_pwd, char *argv)
{
	char	*temp;
	char	*pwd;

	pwd = ft_getcwd();
	if (pwd == NULL)
	{
		if ((temp = ft_strjoin(old_pwd, "/")) == NULL)
			exit(1);
		if ((pwd = ft_strjoin(temp, argv)) == NULL)
			exit(1);
		free(temp);
		g_status = 1;
	}
	if (old_pwd)
		ft_change_env("OLDPWD", old_pwd);
	if (pwd)
		ft_change_env("PWD", pwd);
	free(pwd);
}

void		ft_cd(char **argv)
{
	char	*old_pwd;

	g_status = 0;
	if (argv && *argv && ft_strncmp(argv[0], "-", 2))
	{
		old_pwd = ft_var_of_key("PWD");
		if (argv[0] && argv[1])
			g_status = ft_error1_print();
		else if (chdir(argv[0]) == -1)
			g_status = ft_error2_print(argv);
		else
			ft_change_env_pwd(old_pwd, argv[0]);
	}
	else
		ft_cd_old_or_home(argv);
}
