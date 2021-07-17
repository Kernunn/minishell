#include "double_list_bonus.h"
#include <stdlib.h>
#include "libft.h"

extern t_double_list	*g_cur_command;
extern t_double_list	*g_new_command;

void	clear_new_command(void)
{
	if (g_new_command)
	{
		free(g_new_command->content->buffer);
		g_new_command->content->buffer = NULL;
		g_new_command->content->length = 0;
		g_new_command->content->cur_pos = 0;
		g_new_command->content->available_char = 0;
	}
}

void	delete_new_command(void)
{
	if (g_new_command)
	{
		free(g_new_command->content->buffer);
		free(g_new_command->content);
		free(g_new_command);
		g_new_command = NULL;
	}
}

void	clear_buffer_cur_command(void)
{
	t_buf	*buf;

	if (g_cur_command && g_cur_command != g_new_command)
	{
		buf = g_cur_command->content;
		free(buf->buffer);
		if (!(buf->buffer = ft_strdup(buf->history_str)))
			exit(1);
		buf->length = ft_strlen(buf->history_str);
		buf->cur_pos = buf->length;
	}
}
