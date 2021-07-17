#	ifndef ADD_WORD_OR_OPERATOR_EXTRA_H
#	define ADD_WORD_OR_OPERATOR_EXTRA_H

#include "t_token.h"

int		is_metacharacter(char c);
char	*add_char_in_str(char *old_str, char c);
void	add_word_in_list(char **str, t_list **list, int qoutes);
void	add_parameter(char **str, t_list **list, int quotes);
void	add_backslash_in_quotes(char **str, char **s);
t_type	pipe_or_or(char **str);
t_type	great_or_greatgreat(char **str);
t_type	less_or_lessless(char **str);
t_type	and_or_word(char **str, t_token *token);

#	endif
