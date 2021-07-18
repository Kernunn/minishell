#include "t_command.h"
#include <stdlib.h>

t_simple_command *new_simple_command(void) {
  t_simple_command *simple_command;

  simple_command = malloc(sizeof(t_simple_command));
  if (!simple_command)
	exit(1);
  simple_command->number_of_available_token = 0;
  simple_command->number_of_token = 0;
  simple_command->tokens = NULL;
  simple_command->argv = NULL;
  simple_command->redirection_output = NULL;
  simple_command->redirection_input = NULL;
  return (simple_command);
}

t_command *new_command(void) {
  t_command *command;

  command = malloc(sizeof(t_command));
  if (!command)
	exit(1);
  command->number_of_available_token = 0;
  command->number_of_token = 0;
  command->number_of_available_simple_commands = 0;
  command->number_of_simple_commands = 0;
  command->simple_commands = NULL;
  command->tokens = NULL;
  command->pid = NULL;
  return (command);
}

t_redirection *new_redirection(void) {
  t_redirection *red;

  if (!(red = malloc(sizeof(t_redirection))))
	exit(1);
  red->name_file = NULL;
  red->file_name = NULL;
  red->type_of_redirection = 0;
  red->number_of_token_in_name_file = 0;
  return (red);
}
