#include "libft.h"
#include "process_quotes.h"
#include "add_word_or_operator_extra.h"
#include "add_word_or_operator.h"

extern int g_errno;

t_list *process_quotes(char *str) {
  t_list *list;

  list = NULL;
  while (*str != '\0' && !g_errno) {
	if (*str == ' ' || *str == '\t')
	  add_space_or_tab(&str, &list);
	else if (*str == '\'')
	  add_word_in_single_quotes(&str, &list);
	else if (*str == '\"')
	  add_word_in_double_quotes(&str, &list);
	else if (is_metacharacter(*str) && *str != '\\')
	  add_metacharacter(&str, &list);
	else
	  add_word(&str, &list);
  }
  if (!g_errno)
	add_newline(&list);
  return (list);
}
