/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:21:34 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/11 15:30:11 by bbenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

extern int	g_sigint;
extern int	g_status;

static char	*ft_strjoin_v2(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		exit(1);
	i = 0;
	k = 0;
	while (s1 && s1[i] && s1[i] != '\n')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && *s2 != '\0' && *s2 != '\n')
		new[i + k++] = *s2++;
	new[i + k] = '\0';
	free((char *)s1);
	return (new);
}

static int	print_exit(void)
{
	write(2, "exit\n", 5);
	return (g_status);
}

char		*read_command(void)
{
	char	*tmp;
	int		k;
	char	*str;

	str = ft_strdup("");
	while (1)
	{
		k = get_next_line(0, &tmp);
		if (k == -1)
			exit(1);
		if (g_sigint == 1)
		{
			free(str);
			str = ft_strdup("");
			g_sigint = 0;
		}
		str = ft_strjoin_v2(str, tmp);
		free(tmp);
		if (k == 0 && ft_strlen(str) == 0)
			exit(print_exit());
		if (k == 1)
			break ;
	}
	return (str);
}
