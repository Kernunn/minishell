/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:32:46 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/04 17:41:36 by bbenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_FUNCTIONS_H
# define BUILT_FUNCTIONS_H

void	ft_echo(char **str);
void	ft_env(void);
void	ft_pwd(void);
void	ft_unset(char **key);
void	ft_cd(char **path);
void	ft_exit(char **argv);
void	ft_export(char **key_var);

#endif
