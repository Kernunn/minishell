#include "libft.h"

t_list *ft_lst_at(t_list *begin_list, unsigned int nbr) {
  unsigned int i;

  i = 1;
  while (begin_list && i < nbr) {
	begin_list = begin_list->next;
	i++;
  }
  return (begin_list);
}
