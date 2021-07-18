#include <stdlib.h>
#include <unistd.h>
#include "struct_bonus.h"
#include "insert_char_bonus.h"
#include "delete_char_bonus.h"
#include "escape_sequence_bonus.h"
#include "double_list_bonus.h"
#include "move_right_left_on_screen_bonus.h"
#include "init_term_bonus.h"
#include "cut_copy_paste_bonus.h"
#include "libft.h"

t_double_list *g_history;
t_double_list *g_cur_command;
t_double_list *g_new_command;
extern int g_status;

static void enter(char ch) {
  write(2, &ch, 1);
}

static void ctrl_d(void) {
  if (g_cur_command->content->length == 0) {
	init_term(1);
	write(2, "exit\n", 5);
	exit(g_status);
  }
}

static void new_command(void) {
  if (g_new_command)
	return;
  if (!(g_new_command = create_elem_of_dlist()))
	exit(1);
  g_cur_command = g_new_command;
  save_cursor_position();
}

static void cut_copy_paste(char ch) {
  if (ch == 21)
	cut(g_cur_command->content);
  else if (ch == 25)
	paste(g_cur_command->content);
  else
	copy(g_cur_command->content);
}

void read_input(void) {
  char ch;

  new_command();
  while (1) {
	read(0, &ch, 1);
	if (ch == 21 || ch == 25 || ch == 20)
	  cut_copy_paste(ch);
	else if (ch == 10)
	  return (enter(ch));
	else if (ch == 127)
	  backspace(g_cur_command->content);
	else if (ch == 27)
	  escape_sequence();
	else if (ch == '\004')
	  ctrl_d();
	else if (ft_isprint(ch))
	  insert_char(g_cur_command->content, ch);
  }
}
