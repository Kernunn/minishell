/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right_left_on_screen.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:23:17 by bbenny            #+#    #+#             */
/*   Updated: 2020/12/10 18:09:32 by bbenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_RIGHT_LEFT_ON_SCREEN_BONUS_H
# define MOVE_RIGHT_LEFT_ON_SCREEN_BONUS_H

void	move_right_on_screen(void);
void	move_left_on_screen(void);
void	save_cursor_position(void);
void	move_home(void);
void	move_end(int len);
void	move_n_right_on_screen(int n);
void	move_n_left_on_screen(int n);

#endif
