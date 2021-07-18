#include <signal.h>
#include "read_input_bonus.h"
#include <unistd.h>
#include "double_list_bonus.h"
#include "insert_in_history_bonus.h"
#include "move_right_left_on_screen_bonus.h"
#include "init_term_bonus.h"
#include "clear_bonus.h"
#include "parsing_command.h"
#include "libft.h"
#include "free_commands.h"
#include "ft_error.h"
#include "run_command.h"
#include "t_command.h"
#include "shell_expansion.h"
#include "wildcard_expansion.h"
#include "split_command_into_arguments.h"
#include "copy_env.h"

extern t_double_list *g_cur_command;
extern t_double_list *g_new_command;
int g_status;
int g_errno;
int g_no_promt;
char **g_env;

void type_promt(void) {
  if (!g_no_promt)
	write(2, "$ ", 2);
  g_no_promt = 0;
}

void handler_signal(int type) {
  if (type == SIGINT) {
	write(2, "^C\n$ ", 5);
	g_status = 130;
	g_no_promt = 1;
	clear_new_command();
	clear_buffer_cur_command();
	g_cur_command = g_new_command;
	save_cursor_position();
  }
}

t_list **get_command(void) {
  t_list **commands;

  commands = parsing_command();
  g_no_promt = 0;
  if (g_errno) {
	free_commands(commands);
	commands = NULL;
	print_error();
	g_status = 2;
  }
  return (commands);
}

void run_command(t_list **commands) {
  t_list *tmp_list;
  t_elem_of_list *command;

  while (*commands != NULL && !g_errno) {
	tmp_list = *commands;
	while (tmp_list && !g_errno) {
	  shell_expansion(tmp_list);
	  wildcard_expansion(tmp_list);
	  if (g_errno)
		break;
	  split_command_into_arguments(tmp_list);
	  command = tmp_list->content;
	  run(command->command);
	  if (command->type == AND && g_status)
		break;
	  if (command->type == OR && !g_status)
		break;
	  tmp_list = tmp_list->next;
	}
	commands++;
  }
  g_errno = 0;
}

int main(int argc, char **argv, char **env) {
  t_list **commands;

  ft_copy_env(argc, argv, env);
  init_term(0);
  signal(SIGINT, handler_signal);
  signal(SIGQUIT, handler_signal);
  while (1) {
	type_promt();
	commands = get_command();
	insert_in_history();
	if (!commands) {
	  init_term(0);
	  continue;
	}
	run_command(commands);
	free_commands(commands);
	init_term(0);
  }
  return (0);
}
