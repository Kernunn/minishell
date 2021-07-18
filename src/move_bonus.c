#include "move_right_left_on_screen_bonus.h"
#include "struct_bonus.h"

void move(t_buf *buf, char ch) {
  if (ch == 'C') {
	if (buf->cur_pos < buf->length) {
	  buf->cur_pos += 1;
	  move_right_on_screen();
	}
  }
  if (ch == 'D') {
	if (buf->cur_pos > 0) {
	  buf->cur_pos -= 1;
	  move_left_on_screen();
	}
  }
}

void home_end(t_buf *buf, char ch) {
  if (ch == 'H') {
	if (buf->cur_pos != 0) {
	  buf->cur_pos = 0;
	  move_home();
	}
  }
  if (ch == 'F') {
	if (buf->cur_pos != buf->length) {
	  buf->cur_pos = buf->length;
	  move_end(buf->length);
	}
  }
}

void ctrl_left(t_buf *buf) {
  int i;

  i = 0;
  if (buf->buffer[buf->cur_pos] == ' ') {
	while (buf->cur_pos > 0) {
	  if (buf->buffer[buf->cur_pos] != ' ')
		break;
	  i++;
	  buf->cur_pos--;
	}
  }
  while (buf->cur_pos > 0) {
	i++;
	buf->cur_pos--;
	if (buf->buffer[buf->cur_pos - 1] == ' ')
	  break;
  }
  move_n_left_on_screen(i);
}

void ctrl_right(t_buf *buf) {
  int i;

  i = 0;
  if (buf->buffer[buf->cur_pos] == ' ') {
	while (buf->cur_pos < buf->length) {
	  if (buf->buffer[buf->cur_pos] != ' ')
		break;
	  i++;
	  buf->cur_pos++;
	}
  }
  while (buf->cur_pos < buf->length) {
	if (buf->buffer[buf->cur_pos] == ' ')
	  break;
	i++;
	buf->cur_pos++;
  }
  move_n_right_on_screen(i);
}
