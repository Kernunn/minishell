/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expansion_extra.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:36:13 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/06 18:36:15 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef WILDCARD_EXPANSION_EXTRA_H
#	define WILDCARD_EXPANSION_EXTRA_H

#include "t_command.h"

void	check_ambiguous_redirection(char *str);
int		check_type(t_simple_command *simple_command, int i);

#	endif
