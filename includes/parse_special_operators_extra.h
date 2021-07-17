#	ifndef PARSE_SPECIAL_OPERATORS_EXTRA_H
#	define PARSE_SPECIAL_OPERATORS_EXTRA_H

#include "t_command.h"
#include "t_token.h"

void	redirection(t_simple_command *command, int *k, t_type type, t_type arg);
void	here_document(t_simple_command *command, int *k, t_type arg);
void	add_redirection_in_simple_command(t_simple_command *simple_command,
		int *k);

#	endif
