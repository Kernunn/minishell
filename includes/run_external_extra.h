/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_external_extra.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:40:54 by gmorros           #+#    #+#             */
/*   Updated: 2020/11/27 19:40:55 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RUN_EXTERNAL_EXTRA_H
#	define RUN_EXTERNAL_EXTRA_H

int		file_is_exist(char *pathname);
void	free_array(char **array);
char	**find_path_var(void);
char	*find_path(char **array, char *name);

#	endif
