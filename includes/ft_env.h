/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:08:47 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/11 14:01:51 by bbenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

void	ft_add_env(char *key, char *var);
void	ft_change_env(char *key, char *var);
char	*ft_var_of_key(char *key);
void	ft_add_key_to_export(char *key);

#endif
