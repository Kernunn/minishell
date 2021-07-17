#	ifndef MINISHELL_DEBUG_CHECK_ERROR_SYNTAX_H
#	define MINISHELL_DEBUG_CHECK_ERROR_SYNTAX_H

#include "libft.h"
#include "t_token.h"

int	check_error_syntax(t_list *list, t_type type);
int	check_error_syntax2(t_command *command, t_type type);
int	check_syntax_error3(t_simple_command *sim_command);

#	endif
