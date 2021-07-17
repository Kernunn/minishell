/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right_left_on_screen_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:21:14 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/10 18:19:28 by bbenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_putint_bonus.h"
#include <stdlib.h>

void	move_left_on_screen(void)
{
	char	buf[100];
	char	*buffer;
	char	*str;
	char	*cap;

	buffer = buf;
	if ((cap = tgetstr("le", &buffer)) == NULL)
		exit(1);
	if ((str = tgoto(cap, 0, 0)) == NULL)
		exit(1);
	if ((tputs(str, 1, ft_putint)) == -1)
		exit(1);
}

void	move_right_on_screen(void)
{
	char	buf[100];
	char	*buffer;
	char	*str;
	char	*cap;

	buffer = buf;
	if ((cap = tgetstr("nd", &buffer)) == NULL)
		exit(1);
	if ((str = tgoto(cap, 0, 0)) == NULL)
		exit(1);
	if ((tputs(str, 1, ft_putint)) == -1)
		exit(1);
}

void	move_n_right_on_screen(int n)
{
	char	buf[100];
	char	*buffer;
	int		i;
	char	*str;
	char	*cap;

	i = 0;
	buffer = buf;
	while (i < n)
	{
		if ((cap = tgetstr("nd", &buffer)) == NULL)
			exit(1);
		if ((str = tgoto(cap, 0, 0)) == NULL)
			exit(1);
		if ((tputs(str, 1, ft_putint)) == -1)
			exit(1);
		buffer = buf;
		ft_bzero(buffer, 100);
		i++;
	}
}

void	move_n_left_on_screen(int n)
{
	char	buf[100];
	char	*buffer;
	int		i;
	char	*str;
	char	*cap;

	i = 0;
	buffer = buf;
	while (i < n)
	{
		if ((cap = tgetstr("le", &buffer)) == NULL)
			exit(1);
		if ((str = tgoto(cap, 0, 0)) == NULL)
			exit(1);
		if ((tputs(str, 1, ft_putint)) == -1)
			exit(1);
		buffer = buf;
		ft_bzero(buffer, 100);
		i++;
	}
}
