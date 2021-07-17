/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_external_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:59:32 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/05 18:57:30 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>
#include <stdlib.h>

extern	char **g_env;

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array && *(array + i))
	{
		free(*(array + i));
		i++;
	}
	free(array);
}

int		file_is_exist(char *pathname)
{
	struct stat buf;

	if (!pathname)
		return (0);
	if (stat(pathname, &buf) == -1)
		return (0);
	return (1);
}

char	**find_path_var(void)
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp("PATH=", g_env[i], 5))
			break ;
		i++;
	}
	if (!g_env[i])
		return (NULL);
	return (ft_split(g_env[i] + 5, ':'));
}

char	*find_path(char **array, char *name)
{
	int		i;
	char	*tmp;
	char	*pathname;

	i = 0;
	while (array[i])
	{
		if (!(tmp = ft_strjoin(array[i], "/")))
			exit(1);
		if (!(pathname = ft_strjoin(tmp, name)))
			exit(1);
		free(tmp);
		if (file_is_exist(pathname))
			break ;
		free(pathname);
		pathname = NULL;
		i++;
	}
	return (pathname);
}
