/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_special_operators_extra.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:52:44 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/04 11:27:14 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PARSE_SPECIAL_OPERATORS_EXTRA_H
#	define PARSE_SPECIAL_OPERATORS_EXTRA_H

#include "t_command.h"
#include "t_token.h"

void	redirection(t_simple_command *command, int *k, t_type type, t_type arg);
void	here_document(t_simple_command *command, int *k, t_type arg);
void	add_redirection_in_simple_command(t_simple_command *simple_command,
		int *k);

#	endif
