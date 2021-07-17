#include "double_list_bonus.h"
#include "struct_bonus.h"
#include <stdlib.h>

t_double_list	*create_elem_of_dlist(void)
{
	t_double_list	*new;

	if (!(new = malloc(sizeof(t_double_list))))
		return (NULL);
	if (!(new->content = malloc(sizeof(t_buf))))
	{
		free(new);
		return (NULL);
	}
	new->content->buffer = NULL;
	new->content->available_char = 0;
	new->content->length = 0;
	new->content->cur_pos = 0;
	new->content->history_str = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			ft_dlist_pushback(t_double_list **lst, t_double_list *new)
{
	t_double_list	*begin;

	if (lst)
	{
		begin = *lst;
		if (begin)
		{
			while (begin->next)
				begin = begin->next;
			begin->next = new;
			new->prev = begin;
		}
		else
			*lst = new;
	}
}

t_double_list	*ft_last_dlist(t_double_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
