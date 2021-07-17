#	ifndef FT_ERROR_H
#	define FT_ERROR_H

#include "t_token.h"

void	print_error(void);
void	print_errno(char *str);
int		type_of_error(t_type type);

#	endif
