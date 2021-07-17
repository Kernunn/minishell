/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:48:55 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/15 12:11:35 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_key.h"
#include "ft_get_key.h"
#include "ft_search_env.h"
#include "ft_env.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_print_export.h"

extern int	g_status;
extern char **g_env;
char	**g_env_export;

char		*ft_get_key(char *key_var)
{
	char	*key;
	size_t	len;

	if (!(ft_strchr(key_var, '=')))
		return (ft_strdup(key_var));
	if (ft_strncmp(key_var, ft_strchr(key_var, '='),
				ft_strlen(key_var)) && *(ft_strchr(key_var, '=') - 1) == '+')
		len = ft_strnstr(key_var, "+=", ft_strlen(key_var)) - key_var;
	else
		len = ft_strchr(key_var, '=') - key_var;
	if (len == 0)
		return (ft_strdup(key_var));
	key = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(key, key_var, len + 1);
	return (key);
}

int			ft_check_key(char *var, char *command)
{
	int		i;
	int		status;

	i = 0;
	status = 0;
	if (var && var[0])
	{
		if (ft_isdigit(var[0]))
			status = 1;
		while (var[i])
		{
			if (!ft_isdigit(var[i]) && !ft_isalpha(var[i]) && var[i] != '_')
				status = 1;
			i++;
		}
	}
	if (status)
	{
		write(2, command, ft_strlen(command));
		write(2, ": \'", 3);
		write(2, var, ft_strlen(var));
		write(2, "\': not a valid identifier\n", 26);
		g_status = 1;
	}
	return (status);
}

char		*ft_get_var(char *key_var)
{
	char	*var;
	int		plus;
	char	*temp;
	char	*key;

	plus = 0;
	var = NULL;
	if (ft_strnstr(key_var, "+=", ft_strlen(key_var)))
		plus = 1;
	if (ft_strchr(key_var, '='))
	{
		var = ft_strdup(ft_strchr(key_var, '=') + 1);
		if (plus)
		{
			temp = var;
			if ((key = ft_get_key(key_var)) && ft_var_of_key(key))
			{
				var = ft_strjoin(ft_var_of_key(key), var);
				free(temp);
			}
			free(key);
		}
	}
	return (var);
}

static void	ft_check_unset_key_export(char *key, int i)
{
	int j;

	j = 0;
	if (i > -1)
		return ;
	while (g_env_export && g_env_export[j])
	{
		if ((ft_strncmp(g_env_export[j], key, ft_strlen(key) + 1)) == 0)
		{
			free(g_env_export[j]);
			g_env_export[j] = g_env_export[j + 1];
			while (g_env_export[j])
			{
				g_env_export[j] = g_env_export[j + 1];
				j++;
			}
		}
		else
			j++;
	}
}

void		ft_export(char **argv)
{
	char	*key;
	char	*var;

	var = NULL;
	key = NULL;
	g_status = 0;
	if (*argv == NULL)
		ft_print_export();
	while (*argv)
	{
		if ((key = ft_get_key(*argv)) && !ft_check_key(key, "export"))
		{
			ft_check_unset_key_export(key, -1);
			if ((var = ft_get_var(*argv)) && (ft_search_env(key) == -1))
				ft_add_env(key, var);
			else if (var && ft_search_env(key) > 0)
				ft_change_env(key, var);
			else
				ft_add_key_to_export(key);
			free(var);
		}
		argv++;
		free(key);
	}
}
