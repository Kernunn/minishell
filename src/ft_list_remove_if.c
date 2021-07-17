#include "libft.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *cur;
	t_list *prev;
	t_list *next;

	if (!begin_list)
		return ;
	cur = *begin_list;
	prev = NULL;
	while (cur)
	{
		next = cur->next;
		if (cmp(cur->content, data_ref) == 0)
		{
			if (prev)
				prev->next = next;
			else
				*begin_list = next;
			ft_lstdelone(cur, free);
		}
		else
			prev = cur;
		cur = next;
	}
}
