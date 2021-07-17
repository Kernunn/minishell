/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:47:50 by gmorros           #+#    #+#             */
/*   Updated: 2020/11/26 12:54:25 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef T_TOKEN_H
#	define T_TOKEN_H

typedef enum	e_type
{
	VAR,
	VAR_IN_DOUBLE_QUOTES,
	WORD,
	WORD_IN_DOUBLE_QUOTES,
	WORD_IN_SINGLE_QUOTES,
	PIPE,
	COLON,
	SPACE,
	GREAT,
	GREATGREAT,
	LESS,
	NEWLINE,
	OR,
	AND,
	LESSLESS
}				t_type;

typedef	struct	s_token
{
	char	*str;
	t_type	type;
}				t_token;

#	endif
