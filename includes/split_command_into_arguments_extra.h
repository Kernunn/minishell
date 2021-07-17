#	ifndef SPLIT_COMMAND_INTO_ARGUMENTS_EXTRA_H
#	define SPLIT_COMMAND_INTO_ARGUMENTS_EXTRA_H

#include "t_token.h"

char	**str_to_argv(t_token *token);
char	**merge_array(char **first, char **second);
void	add_new_arguments(char ***argv, t_token *token, int *space);
void	join_to_old_arg(char ***argv, t_token *token, int *space);

#	endif
