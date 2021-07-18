#include "t_command.h"
#include "libft.h"
#include "new_struct.h"
#include "insert_in_command.h"
#include "parse_special_operators_extra.h"
#include "check_error_syntax.h"

extern int g_errno;

static void parse_redirection(t_command *command) {
  int i;
  int j;
  t_type type;

  i = 0;
  while (i < command->number_of_simple_commands && !g_errno) {
	j = 0;
	while (j < command->simple_commands[i]->number_of_token && !g_errno) {
	  type = command->simple_commands[i]->tokens[j]->type;
	  if (type == GREAT || type == GREATGREAT || type == LESS
		  || type == LESSLESS)
		add_redirection_in_simple_command(command->simple_commands[i],
										  &j);
	  j++;
	}
	i++;
  }
}

static void add_token_in_simple_command(t_command *command, int k,
										t_simple_command **simple_command) {
  if (*simple_command == NULL)
	*simple_command = new_simple_command();
  insert_token_in_simple_command(command->tokens[k], *simple_command);
  command->tokens[k] = NULL;
}

static void add_simple_command(t_command *command,
							   t_simple_command **simple_command) {
  if ((g_errno = check_syntax_error3(*simple_command)))
	return;
  insert_simple_command(*simple_command, command);
  *simple_command = NULL;
}

static void parse_pipes(t_command *command) {
  int i;
  t_type type;
  t_simple_command *cur_simple_command;

  cur_simple_command = NULL;
  i = 0;
  while (i < command->number_of_token && !g_errno) {
	type = command->tokens[i]->type;
	if (type == PIPE)
	  add_simple_command(command, &cur_simple_command);
	else
	  add_token_in_simple_command(command, i, &cur_simple_command);
	i++;
  }
  if (!g_errno)
	add_simple_command(command, &cur_simple_command);
}

void parse_special_operators(t_list **commands) {
  int i;
  t_list *tmp;

  i = 0;
  while (commands[i] && !g_errno) {
	tmp = commands[i];
	while (tmp && !g_errno) {
	  parse_pipes(((t_elem_of_list *) tmp->content)->command);
	  if (!g_errno)
		parse_redirection(((t_elem_of_list *) tmp->content)->command);
	  tmp = tmp->next;
	}
	i++;
  }
}
