#include "ft_get_key.h"
#include "ft_search_env.h"
#include "ft_env.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

extern int	g_status;
extern char **g_env;
extern char	**g_env_export;

static void	ft_change_ptr(char **ptr1, char **ptr2)
{
	char	*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

static void	ft_sort_double_ptr(char ***env)
{
	int		i;
	int		j;
	char	*key;
	char	*key_next;

	j = 0;
	while ((*env) && (*env)[j] && (*env)[j + 1])
	{
		i = 0;
		while (*env && (*env)[i] && (*env)[i + 1])
		{
			if (!(key = ft_get_key((*env)[i])) ||
				!(key_next = ft_get_key((*env)[i + 1])))
				exit(1);
			if (ft_strncmp(key, key_next, ft_strlen(key) + 1) > 0)
				ft_change_ptr(&(*env)[i], &(*env)[i + 1]);
			i++;
			free(key);
			free(key_next);
		}
		j++;
	}
}

static void	ft_add_str_to_arr(char **str, int i)
{
	char	*key;
	char	*part;
	char	*tmp;

	if (!(key = ft_get_key(g_env[i])))
		exit(1);
	if (!(part = ft_strjoin(key, "=\"")))
		exit(1);
	if (!(tmp = ft_strjoin(ft_var_of_key(key), "\"")))
		exit(1);
	free(key);
	key = tmp;
	if (!(tmp = ft_strjoin(part, tmp)))
		exit(1);
	free(part);
	free(key);
	*str = tmp;
}

static char	**ft_env_create_sort(void)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	while (g_env && g_env[i])
		i++;
	j = 0;
	while (g_env_export && g_env_export[j])
		j++;
	if (!(tmp = (char **)malloc(sizeof(char *) * (i + 1 + j))))
		exit(1);
	i = 0;
	while (g_env && g_env[i])
	{
		ft_add_str_to_arr(&(tmp[i]), i);
		i++;
	}
	j = 0;
	while (g_env_export && g_env_export[j])
		tmp[i++] = ft_get_key(g_env_export[j++]);
	tmp[i] = NULL;
	ft_sort_double_ptr(&tmp);
	return (tmp);
}

void		ft_print_export(void)
{
	int		i;
	char	*key;
	char	**env;

	i = 0;
	env = ft_env_create_sort();
	while (env && env[i] && (key = ft_get_key(env[i])))
	{
		write(1, "declare -x ", 11);
		write(1, env[i], ft_strlen(env[i]));
		write(1, "\n", 1);
		free(key);
		i++;
	}
	i = 0;
	while (env && env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
	g_status = 0;
}
