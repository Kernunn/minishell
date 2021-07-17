/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:13:04 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/11 18:51:01 by bbenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

extern int	g_status;
extern char	**g_env;

void	ft_copy_env(int argc, char **argv, char **environ)
{
	int i;

	i = 0;
	if (!argc && !argv)
		exit(255);
	while (environ[i])
		i++;
	g_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (g_env == NULL)
		exit(1);
	i = 0;
	while (environ[i])
	{
		g_env[i] = ft_strdup(environ[i]);
		if (g_env[i] == NULL)
			exit(1);
		i++;
	}
	g_env[i] = NULL;
}

void	ft_env(void)
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		write(1, g_env[i], ft_strlen(g_env[i]));
		write(1, "\n", 1);
		i++;
	}
	g_status = 0;
}
