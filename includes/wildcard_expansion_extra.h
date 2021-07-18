#	ifndef WILDCARD_EXPANSION_EXTRA_H
#	define WILDCARD_EXPANSION_EXTRA_H

#include "t_command.h"

void check_ambiguous_redirection(char *str);
int check_type(t_simple_command *simple_command, int i);

#	endif
