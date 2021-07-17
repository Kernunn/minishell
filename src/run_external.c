/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_external.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:03:30 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/05 19:00:35 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_command.h"
#include <stdlib.h>
#include "run_external_extra.h"
#include <unistd.h>
#include "libft.h"
#include "limits.h"
#include "ft_error.h"

extern int	g_status;
extern char	**g_env;

static char	*path_based_on_env(char *name)
{
	char	*pathname;
	char	**array;

	if (!name)
		exit(1);
	if (!(array = find_path_var()))
	{
		free(name);
		return (NULL);
	}
	pathname = find_path(array, name);
	free_array(array);
	free(name);
	return (pathname);
}

static char	*relative_path(char *name)
{
	char *pathname;
	char *buf;
	char *tmp;

	if ((buf = malloc(sizeof(char) * PATH_MAX)) == NULL)
		exit(1);
	if ((buf = getcwd(buf, PATH_MAX)) == NULL)
		exit(1);
	if (!(tmp = ft_strjoin(buf, "/")))
		exit(1);
	if (!(pathname = ft_strjoin(tmp, name)))
		exit(1);
	free(buf);
	free(tmp);
	return (pathname);
}

static char	*find_program(char *name)
{
	char	*pathname;

	if (*name == '/')
	{
		if (!(pathname = ft_strdup(name)))
			exit(1);
	}
	else if (ft_strchr(name, '/') == NULL)
		pathname = path_based_on_env(ft_strjoin("/", name));
	else
		pathname = relative_path(name);
	if (file_is_exist(pathname) == 0)
	{
		write(2, name, ft_strlen(name));
		write(2, ": command not found\n", 20);
		free(pathname);
		exit(127);
	}
	return (pathname);
}

void		executing_external(t_simple_command *simple_command)
{
	char	*pathname;

	pathname = find_program((simple_command->argv)[0]);
	execve(pathname, simple_command->argv, g_env);
	print_errno(simple_command->argv[0]);
	free(pathname);
	exit(126);
}
