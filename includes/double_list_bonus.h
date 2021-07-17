#	ifndef DOUBLE_LIST_BONUS_H
#	define DOUBLE_LIST_BONUS_H

#include "struct_bonus.h"

typedef struct	s_double_list
{
	t_buf					*content;
	struct s_double_list	*prev;
	struct s_double_list	*next;
}				t_double_list;

t_double_list	*create_elem_of_dlist(void);
void			ft_dlist_pushback(t_double_list **begin, t_double_list *cur);
t_double_list	*ft_last_dlist(t_double_list *lst);

#	endif
