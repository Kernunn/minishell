/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:32:58 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/10 19:03:32 by bbenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "init_term_bonus.h"

extern int g_status;

static int	ft_check_digit(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

static int	ft_write_er(char *str)
{
	write(2, "exit: ", 6);
	write(2, str, ft_strlen(str));
	write(2, ": numeric argument required\n", 28);
	return (255);
}

void		ft_exit(char **argv)
{
	int		num;
	char	*str;

	write(2, "exit\n", 5);
	if (*argv)
	{
		str = ft_strdup(*argv);
		num = ft_atoi(str);
		if (!ft_check_digit(str) || (num == 0 && *str == '-')
				|| (num == -1 && *str != '-'))
			num = ft_write_er(str);
		else if (ft_check_digit(str) && argv[1])
		{
			write(2, "exit: too many arguments\n", 25);
			g_status = 1;
			free(str);
			return ;
		}
		free(str);
		exit(num);
	}
	else
		init_term(1);
	exit(g_status);
}
