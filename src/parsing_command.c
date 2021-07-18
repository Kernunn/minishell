#include <stdlib.h>
#include "libft.h"
#include "read_input.h"
#include "process_quotes.h"
#include "split_into_command.h"
#include "parse_special_operators.h"
#include "t_token.h"

extern int g_errno;
extern int g_status;

void ft_clear(t_list **list) {
  t_list *tmp;

  tmp = *list;
  while (tmp) {
	free(((t_token *) (tmp->content))->str);
	tmp = tmp->next;
  }
  ft_lstclear(list, free);
}

t_list **parsing_command(void) {
  t_list *list;
  char *str;
  t_list **commands;

  list = NULL;
  str = NULL;
  commands = NULL;
  str = read_command();
  list = process_quotes(str);
  free(str);
  if (g_errno)
	ft_clear(&list);
  if (g_errno == 0)
	commands = split_into_command(list);
  ft_lstclear(&list, free);
  if (g_errno == 0)
	parse_special_operators(commands);
  return (commands);
}
