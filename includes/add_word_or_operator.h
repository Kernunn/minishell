/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word_or_operator.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:46:11 by gmorros           #+#    #+#             */
/*   Updated: 2020/11/26 12:51:06 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef ADD_WORD_OR_OPERATOR_H
#	define ADD_WORD_OR_OPERATOR_H

#include "libft.h"

void	add_word_in_single_quotes(char **str, t_list **list);
void	add_word_in_double_quotes(char **str, t_list **list);
void	add_metacharacter(char **str, t_list **list);
void	add_word(char **str, t_list **list);
void	add_space_or_tab(char **str, t_list **list);
void	add_newline(t_list **list);

#	endif
