#include <unistd.h>
#include "move_right_left_on_screen_bonus.h"
#include "struct_bonus.h"
#include "delete_char_bonus.h"
#include "move_bonus.h"
#include "double_list_bonus.h"
#include "up_down_arrow_bonus.h"

extern t_double_list	*g_cur_command;

static void	ctrl(void)
{
	char	ch;

	read(0, &ch, 1);
	if (ch == ';')
	{
		read(0, &ch, 1);
		if (ch == '5')
		{
			read(0, &ch, 1);
			if (ch == 'D')
				ctrl_left(g_cur_command->content);
			if (ch == 'C')
				ctrl_right(g_cur_command->content);
		}
	}
}

void		escape_sequence(void)
{
	char	ch;

	read(0, &ch, 1);
	if (ch == 91)
	{
		read(0, &ch, 1);
		if (ch == 'A')
			up_arrow();
		if (ch == 'B')
			down_arrow();
		if (ch == 'C' || ch == 'D')
			move(g_cur_command->content, ch);
		if (ch == 'H' || ch == 'F')
			home_end(g_cur_command->content, ch);
		if (ch == '3')
			delete(g_cur_command->content);
		if (ch == '1')
			ctrl();
	}
}
