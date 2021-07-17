/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:36:56 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/06 18:37:13 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef WILDCARD_UTILS_H
#	define WILDCARD_UTILS_H

#include "libft.h"

t_list	*ft_list_last(t_list *begin_list);
int		ft_get_all_files(t_list **list, char *pwd, char c);
char	*ft_list_to_str_with_spaces(t_list **lst);
char	*ft_change_pwd_until_star(char *path, char **pwd);
char	*ft_change_str_match(char *str);

#	endif
