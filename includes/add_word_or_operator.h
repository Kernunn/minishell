#	ifndef ADD_WORD_OR_OPERATOR_H
#	define ADD_WORD_OR_OPERATOR_H

#include "libft.h"

void	add_word_in_single_quotes(char **str, t_list **list);
void	add_word_in_double_quotes(char **str, t_list **list);
void	add_metacharacter(char **str, t_list **list);
void	add_word(char **str, t_list **list);
void	add_space_or_tab(char **str, t_list **list);
void	add_newline(t_list **list);

#	endif
