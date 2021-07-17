#include "insert_delete_on_screen_bonus.h"
#include "libft.h"

void	change_str_on_screen(int len_str, char *str_next)
{
	if (len_str)
		delete_line_on_screen(len_str);
	if (str_next)
		ft_putstr_fd(str_next, 2);
}
