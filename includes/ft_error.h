/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:51:50 by gmorros           #+#    #+#             */
/*   Updated: 2020/11/26 12:54:42 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_ERROR_H
#	define FT_ERROR_H

#include "t_token.h"

void	print_error(void);
void	print_errno(char *str);
int		type_of_error(t_type type);

#	endif
