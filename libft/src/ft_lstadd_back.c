#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new) {
  t_list *begin;

  if (lst) {
	begin = *lst;
	if (begin) {
	  while (begin->next)
		begin = begin->next;
	  begin->next = new;
	} else
	  *lst = new;
  }
}
