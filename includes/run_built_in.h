#	ifndef RUN_BUILT_IN_H
#	define RUN_BUILT_IN_H

#include "t_command.h"

void	executing_built_in(t_command *command, int k, int count);
int		is_built_in(char *command);

#	endif
