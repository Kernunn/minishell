#include <stdlib.h>
#include "t_token.h"
#include "t_command.h"
#include "split_into_command.h"
#include "new_struct.h"
#include "check_error_syntax.h"
#include "insert_in_command.h"

extern int g_errno;

static void add_command_list(t_list ***commands, t_list **com_list, t_type type) {
  size_t i;
  t_list **new_array;

  if ((g_errno = check_error_syntax(*com_list, type)))
	return;
  i = 0;
  while (*commands && *(*commands + i) != NULL)
	i++;
  new_array = malloc((i + 2) * sizeof(t_list *));
  if (!new_array)
	exit(1);
  new_array[i] = *com_list;
  new_array[i + 1] = NULL;
  *com_list = NULL;
  while (i != 0) {
	i--;
	new_array[i] = *(*commands + i);
  }
  free(*commands);
  *commands = new_array;
}

static void add_command_in_list(t_list **command_list, t_command **command,
								t_type type) {
  t_elem_of_list *element_of_list;

  if ((g_errno = check_error_syntax2(*command, type)))
	return;
  if (!(element_of_list = malloc(sizeof(t_elem_of_list))))
	exit(1);
  element_of_list->command = *command;
  *command = NULL;
  element_of_list->type = type;
  ft_lstadd_back(command_list, ft_lstnew(element_of_list));
}

static void add_token_in_command(t_command **current_command,
								 t_list *list) {
  if (*current_command == NULL)
	*current_command = new_command();
  insert_token(list->content, *current_command);
  list->content = NULL;
}

t_list **split_into_command(t_list *list) {
  t_list **commands;
  t_list *command_list;
  t_command *current_command;
  t_type type;

  commands = NULL;
  command_list = NULL;
  current_command = NULL;
  while (list && !g_errno) {
	type = ((t_token *) list->content)->type;
	if (type == COLON || type == NEWLINE) {
	  if (current_command != NULL)
		add_command_in_list(&command_list, &current_command, type);
	  add_command_list(&commands, &command_list, type);
	} else if (type == AND || type == OR)
	  add_command_in_list(&command_list, &current_command, type);
	else
	  add_token_in_command(&current_command, list);
	list = list->next;
  }
  return (commands);
}
