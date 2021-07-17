#include "libft.h"
#include <stdlib.h>

int	remove_hidden(char *content, char *match_str)
{
	char	*ptr_slash;

	if (match_str[0] == '.')
		return (1);
	ptr_slash = ft_strrchr(content, '/');
	if (ptr_slash == NULL)
	{
		if (content[0] == '.')
			return (0);
		return (1);
	}
	else
	{
		if (*(ptr_slash + 1) == '.')
			return (0);
		return (1);
	}
}
