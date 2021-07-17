#	ifndef T_COMMAND_H
#	define T_COMMAND_H

#include "t_token.h"
#include "libft.h"

typedef struct	s_redirection
{
	char	*file_name;
	int		number_of_token_in_name_file;
	t_token	**name_file;
	t_type	type_of_redirection;
}				t_redirection;

typedef	struct	s_simple_command
{
	int		number_of_available_token;
	int		number_of_token;
	t_token	**tokens;
	char	**argv;
	t_list	*redirection_input;
	t_list	*redirection_output;
}				t_simple_command;

typedef struct	s_command
{
	int					number_of_available_token;
	int					number_of_token;
	int					number_of_available_simple_commands;
	int					number_of_simple_commands;
	int					*pid;
	t_simple_command	**simple_commands;
	t_token				**tokens;
}				t_command;

typedef struct	s_elem_of_list
{
	t_command				*command;
	t_type					type;
}				t_elem_of_list;

#	endif
