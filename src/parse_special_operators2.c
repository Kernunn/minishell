/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_special_operators2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:45:24 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/03 17:45:39 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_command.h"
#include <stdlib.h>
#include "parse_special_operators_extra.h"

extern int g_errno;

void	add_redirection_in_simple_command(t_simple_command *simple_command,
		int *k)
{
	t_type	type;

	type = simple_command->tokens[*k]->type;
	free(simple_command->tokens[*k]);
	simple_command->tokens[*k] = NULL;
	if ((*k)++ + 1 >= simple_command->number_of_token)
		g_errno = 3;
	if (g_errno)
		return ;
	if ((simple_command->tokens[*k])->type == SPACE)
	{
		free(simple_command->tokens[*k]);
		simple_command->tokens[(*k)++] = NULL;
	}
	if (*k >= simple_command->number_of_token)
		g_errno = 3;
	if (g_errno)
		return ;
	if (type == LESSLESS)
		here_document(simple_command, k, simple_command->tokens[*k]->type);
	else
		redirection(simple_command, k, type, simple_command->tokens[*k]->type);
}
