/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_built_in.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:53:35 by gmorros           #+#    #+#             */
/*   Updated: 2020/11/27 19:54:50 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RUN_BUILT_IN_H
#	define RUN_BUILT_IN_H

#include "t_command.h"

void	executing_built_in(t_command *command, int k, int count);
int		is_built_in(char *command);

#	endif
