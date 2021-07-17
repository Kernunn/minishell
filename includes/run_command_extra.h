/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command_extra.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:54:05 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/10 21:07:12 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RUN_COMMAND_EXTRA_H
#	define RUN_COMMAND_EXTRA_H

#include "t_command.h"

void	save_and_restore(int *tmpfd, int options, int *rpipe);
void	redirection_input(t_list *lst, int lpipe[2]);
void	redirection_output(t_list *lst, int rpipe[2]);

#	endif
