/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:09:29 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/08 10:28:32 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_token.h"
#include <string.h>
#include <errno.h>
#include "libft.h"

extern int g_errno;

int		type_of_error(t_type type)
{
	if (type == PIPE)
		return (6);
	else if (type == GREAT)
		return (7);
	else if (type == GREATGREAT)
		return (8);
	else if (type == LESS)
		return (9);
	else if (type == LESSLESS)
		return (10);
	else if (type == OR)
		return (4);
	else if (type == AND)
		return (5);
	else
		return (3);
}

void	print_error(void)
{
	if (g_errno == 1)
		write(2, "bash: syntax error missing single quote\n", 40);
	if (g_errno == 2)
		write(2, "bash: syntax error missing double quote\n", 40);
	if (g_errno == 3)
		write(2, "bash: syntax error unexpected token `;' or newline\n", 51);
	if (g_errno == 4)
		write(2, "bash: syntax error near unexpected token `||'\n", 46);
	if (g_errno == 5)
		write(2, "bash: syntax error near unexpected token `&&'\n", 46);
	if (g_errno == 6)
		write(2, "bash: syntax error near unexpected token `|'\n", 45);
	if (g_errno == 7)
		write(2, "bash: syntax error near unexpected token `>'\n", 45);
	if (g_errno == 8)
		write(2, "bash: syntax error near unexpected token `>>'\n", 46);
	if (g_errno == 9)
		write(2, "bash: syntax error near unexpected token `<'\n", 45);
	if (g_errno == 10)
		write(2, "bash: syntax error near unexpected token `<<'\n", 46);
	g_errno = 0;
}

void	print_errno(char *name)
{
	char	*tmp1;

	write(2, "bash: ", 6);
	write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	tmp1 = strerror(errno);
	write(2, tmp1, ft_strlen(tmp1));
	write(2, "\n", 1);
}
