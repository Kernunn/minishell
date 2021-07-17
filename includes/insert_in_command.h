/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_in_command.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:45:58 by gmorros           #+#    #+#             */
/*   Updated: 2020/11/26 12:55:09 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef INSERT_IN_COMMAND_H
#	define INSERT_IN_COMMAND_H

#include "t_token.h"
#include "t_command.h"

void		insert_token(t_token *argument,
		struct s_command *simple_command);
void		insert_token_in_simple_command(t_token *argument,
		t_simple_command *command);
void		insert_simple_command(t_simple_command *simple_command,
		t_command *command);

#	endif
