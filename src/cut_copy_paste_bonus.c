#include <stdlib.h>
#include "libft.h"
#include "insert_delete_on_screen_bonus.h"
#include "struct_bonus.h"

char *g_copy_buffer;

void cut(t_buf *buf) {
  char *tmp;

  if (!buf->buffer || buf->cur_pos == 0) {
	free(g_copy_buffer);
	if (!(g_copy_buffer = ft_strdup("")))
	  exit(1);
	return;
  }
  free(g_copy_buffer);
  if (!(g_copy_buffer = ft_substr(buf->buffer, 0, buf->cur_pos)))
	exit(1);
  if (!(tmp = ft_substr(buf->buffer, buf->cur_pos,
						buf->length - buf->cur_pos)))
	exit(1);
  free(buf->buffer);
  delete_line_on_screen(buf->cur_pos);
  buf->buffer = tmp;
  buf->length = ft_strlen(buf->buffer);
  buf->available_char = buf->length + 1;
  buf->cur_pos = 0;
}

void copy(t_buf *buf) {
  free(g_copy_buffer);
  if (buf->buffer)
	g_copy_buffer = ft_substr(buf->buffer, 0, buf->cur_pos);
  else
	g_copy_buffer = ft_strdup("");
  if (!g_copy_buffer)
	exit(1);
}

void paste(t_buf *buf) {
  char *tmp;
  char *tmp2;

  if (!g_copy_buffer || ft_strlen(g_copy_buffer) == 0)
	return;
  if (!buf->buffer)
	if (!(buf->buffer = ft_strdup("")))
	  exit(1);
  if (!(tmp = ft_substr(buf->buffer, 0, buf->cur_pos)))
	exit(1);
  if (!(tmp2 = ft_strjoin(tmp, g_copy_buffer)))
	exit(1);
  free(tmp);
  if (!(tmp = ft_strjoin(tmp2, buf->buffer + buf->cur_pos)))
	exit(1);
  free(buf->buffer);
  free(tmp2);
  insert_line_on_screen(g_copy_buffer);
  buf->buffer = tmp;
  buf->length = ft_strlen(buf->buffer);
  buf->available_char = buf->length + 1;
  buf->cur_pos += ft_strlen(g_copy_buffer);
}
