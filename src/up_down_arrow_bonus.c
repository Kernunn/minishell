#include "double_list_bonus.h"
#include <stdlib.h>
#include "change_str_on_screen_bonus.h"

extern t_double_list	*g_history;
extern t_double_list	*g_cur_command;
extern t_double_list	*g_new_command;

void	up_arrow(void)
{
	int	old_length;

	old_length = g_cur_command->content->length;
	if (g_cur_command->prev == NULL)
	{
		if (!g_history || g_history == g_cur_command)
			return ;
		g_cur_command = ft_last_dlist(g_history);
	}
	else
		g_cur_command = g_cur_command->prev;
	change_str_on_screen(old_length, g_cur_command->content->buffer);
	g_cur_command->content->cur_pos = g_cur_command->content->length;
}

void	down_arrow(void)
{
	int	old_length;

	old_length = g_cur_command->content->length;
	if (g_cur_command->next == NULL)
	{
		if (!g_history || g_cur_command == g_new_command)
			return ;
		g_cur_command = g_new_command;
	}
	else
		g_cur_command = g_cur_command->next;
	change_str_on_screen(old_length, g_cur_command->content->buffer);
	g_cur_command->content->cur_pos = g_cur_command->content->length;
}
