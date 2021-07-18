#include "double_list_bonus.h"
#include <stdlib.h>
#include "libft.h"
#include "clear_bonus.h"

extern t_double_list *g_history;
extern t_double_list *g_cur_command;
extern t_double_list *g_new_command;

void copy_buf(t_buf *buf) {
  if (g_cur_command != g_new_command) {
	free(g_new_command->content->buffer);
	if (!(g_new_command->content->buffer = ft_strdup(buf->buffer)))
	  exit(1);
	g_new_command->content->length = buf->length;
	g_new_command->content->cur_pos = buf->cur_pos;
  }
  if (!(g_new_command->content->history_str = ft_strdup(buf->buffer)))
	exit(1);
}

static int check(t_buf *buf) {
  t_double_list *tmp;
  int i;

  i = 0;
  if (!buf->buffer)
	return (0);
  while (buf->buffer[i]) {
	if (buf->buffer[i] != ' ')
	  break;
	i++;
  }
  if (!buf->buffer[i])
	return (0);
  if (!(tmp = ft_last_dlist(g_history)))
	return (1);
  if (ft_strncmp(tmp->content->history_str, buf->buffer,
				 ft_strlen(tmp->content->history_str) + 1) == 0)
	return (0);
  return (1);
}

void insert_in_history(void) {
  t_buf *buf;

  buf = g_cur_command->content;
  if (check(buf)) {
	copy_buf(buf);
	ft_dlist_pushback(&g_history, g_new_command);
  } else
	delete_new_command();
  if (g_cur_command != g_new_command && g_new_command)
	clear_buffer_cur_command();
  g_new_command = NULL;
  g_cur_command = NULL;
}
