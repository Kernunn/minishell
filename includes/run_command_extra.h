#	ifndef RUN_COMMAND_EXTRA_H
#	define RUN_COMMAND_EXTRA_H

#include "t_command.h"

void	save_and_restore(int *tmpfd, int options, int *rpipe);
void	redirection_input(t_list *lst, int lpipe[2]);
void	redirection_output(t_list *lst, int rpipe[2]);

#	endif
