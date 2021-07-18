#	ifndef NEW_STRUCT_H
#	define NEW_STRUCT_H

#include "t_command.h"

t_simple_command *new_simple_command(void);
t_command *new_command(void);
t_redirection *new_redirection(void);

#	endif
