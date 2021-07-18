#include "libft.h"
#include "wildcard.h"
#include <stdlib.h>

void wildcard(char **str) {
  char *copy_str;
  t_list **list;

  copy_str = *str;
  if (!(list = malloc(sizeof(t_list *))))
	exit(1);
  *list = NULL;
  *str = expantion_stars(copy_str, list, 0);
  free(list);
  if (ft_strncmp(*str, "", 1) == 0) {
	free(*str);
	*str = copy_str;
  } else
	free(copy_str);
}
