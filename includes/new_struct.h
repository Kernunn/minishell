/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:46:12 by gmorros           #+#    #+#             */
/*   Updated: 2020/11/26 12:52:17 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef NEW_STRUCT_H
#	define NEW_STRUCT_H

#include "t_command.h"

t_simple_command	*new_simple_command(void);
t_command			*new_command(void);
t_redirection		*new_redirection(void);

#	endif
