#include <stdlib.h>
#include "libft.h"
#include "read_input_bonus.h"
#include "process_quotes.h"
#include "split_into_command.h"
#include "parse_special_operators.h"
#include "t_token.h"
#include "double_list_bonus.h"
#include "init_term_bonus.h"

extern int				g_errno;
extern int				g_status;
extern t_double_list	*g_cur_command;

static void	ft_clear(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (tmp)
	{
		free(((t_token*)(tmp->content))->str);
		tmp = tmp->next;
	}
	ft_lstclear(list, free);
}

t_list		**parsing_command(void)
{
	t_list		*list;
	t_list		**commands;

	list = NULL;
	commands = NULL;
	read_input();
	init_term(1);
	if (!g_cur_command || !g_cur_command->content->buffer)
		return (NULL);
	list = process_quotes(g_cur_command->content->buffer);
	if (g_errno)
		ft_clear(&list);
	if (g_errno == 0)
		commands = split_into_command(list);
	ft_lstclear(&list, free);
	if (g_errno == 0)
		parse_special_operators(commands);
	return (commands);
}
