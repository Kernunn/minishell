/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command_extra2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:53:29 by gmorros           #+#    #+#             */
/*   Updated: 2020/12/12 17:53:37 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		save_and_restore(int *tmpfd, int options, int *rpipe)
{
	if (options == 0)
	{
		tmpfd[0] = dup(0);
		tmpfd[1] = dup(1);
	}
	else
	{
		dup2(tmpfd[0], 0);
		dup2(tmpfd[1], 1);
		close(tmpfd[0]);
		close(tmpfd[1]);
		if (rpipe)
		{
			close(rpipe[0]);
			close(rpipe[1]);
		}
	}
}
