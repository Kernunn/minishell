/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:12:59 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/10 22:22:40 by bbenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_search_env.h"

extern int g_status;
extern char **g_env;

int		ft_search_env(char *key)
{
	char	*key_with_eq;
	int		i;

	if ((key_with_eq = ft_strjoin(key, "=")) == NULL)
		exit(1);
	i = 0;
	while (g_env[i]
			&& ft_strncmp(g_env[i], key_with_eq, ft_strlen(key_with_eq)))
		i++;
	if (key_with_eq)
		free(key_with_eq);
	if (!g_env[i])
		return (-1);
	return (i);
}

char	*ft_newstr_env(char *key, char *var)
{
	char *key_eq;
	char *input_key;

	key_eq = ft_strjoin(key, "=");
	if (!key_eq)
		exit(1);
	input_key = ft_strjoin(key_eq, var);
	if (!input_key)
		exit(1);
	free(key_eq);
	return (input_key);
}

void	ft_add_env(char *key, char *var)
{
	char	*newstr_env;
	int		i;
	char	**tmp;

	i = 0;
	newstr_env = ft_newstr_env(key, var);
	tmp = g_env;
	while (g_env[i])
		i++;
	g_env = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tmp[i])
	{
		g_env[i] = ft_strdup(tmp[i]);
		i++;
	}
	g_env[i] = ft_strdup(newstr_env);
	if (!(g_env[i]))
		exit(1);
	g_env[i + 1] = NULL;
	free(newstr_env);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void	ft_change_env(char *key, char *var)
{
	int		i;
	char	*newstr_env;

	i = ft_search_env(key);
	if (i == -1)
		ft_add_env(key, var);
	else
	{
		newstr_env = var && key ? ft_newstr_env(key, var) : ft_strdup(key);
		free(g_env[i]);
		g_env[i] = ft_strdup(newstr_env);
		if (!(g_env[i]))
			exit(1);
		free(newstr_env);
	}
}

char	*ft_var_of_key(char *key)
{
	int		i;
	char	*str;

	str = NULL;
	i = ft_search_env(key);
	if (i >= 0)
		str = g_env[i] + ft_strlen(key) + 1;
	return (str);
}
