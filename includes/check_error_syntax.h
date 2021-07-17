/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_syntax.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:16:45 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/01 19:17:15 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_DEBUG_CHECK_ERROR_SYNTAX_H
#	define MINISHELL_DEBUG_CHECK_ERROR_SYNTAX_H

#include "libft.h"
#include "t_token.h"

int	check_error_syntax(t_list *list, t_type type);
int	check_error_syntax2(t_command *command, t_type type);
int	check_syntax_error3(t_simple_command *sim_command);

#	endif
