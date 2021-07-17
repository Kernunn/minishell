/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:38:21 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/06 18:38:22 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SORT_H
#	define SORT_H

void	ft_list_sort(t_list **begin_list, int (*cmp)());
int		ft_alphabet_strcmp(char *str1, char *str2);

#	endif
