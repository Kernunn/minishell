#include "libft.h"
#include <stdlib.h>
#include "ft_search_env.h"

extern char	**g_env_export;

static void	ft_free_double_ptr(char ***tmp)
{
	int i;

	i = 0;
	while ((*tmp)[i])
		free((*tmp)[i++]);
	free(*tmp);
}

void		ft_add_to_export(char *key)
{
	int		i;
	char	**tmp;
	int		status;

	status = 1;
	i = 0;
	tmp = g_env_export;
	while (g_env_export && g_env_export[i] &&
		(status = ft_strncmp(key, g_env_export[i], ft_strlen(key) + 1)))
		i++;
	if (!status)
		return ;
	if (!(g_env_export = (char **)malloc(sizeof(char *) * (i + 2))))
		exit(1);
	i = 0;
	while (tmp && tmp[i])
	{
		if (!(g_env_export[i] = ft_strdup(tmp[i])))
			exit(1);
		i++;
	}
	if (!(g_env_export[i] = ft_strdup(key)))
		exit(1);
	g_env_export[i + 1] = NULL;
	ft_free_double_ptr(&tmp);
}

void		ft_add_key_to_export(char *key)
{
	if (g_env_export == NULL && ft_search_env(key) == -1)
	{
		if (!(g_env_export = (char **)malloc(sizeof(char *) * 2)))
			exit(1);
		if (!(g_env_export[0] = ft_strdup(key)))
			exit(1);
		g_env_export[1] = NULL;
	}
	else if (ft_search_env(key) == -1)
		ft_add_to_export(key);
}
