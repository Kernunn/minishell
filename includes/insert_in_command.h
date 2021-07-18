#	ifndef INSERT_IN_COMMAND_H
#	define INSERT_IN_COMMAND_H

#include "t_token.h"
#include "t_command.h"

void insert_token(t_token *argument,
				  struct s_command *simple_command);
void insert_token_in_simple_command(t_token *argument,
									t_simple_command *command);
void insert_simple_command(t_simple_command *simple_command,
						   t_command *command);

#	endif
