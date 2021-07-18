#include <term.h>
#include "libft.h"
#include "ft_putint_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int ft_putint(int c) {
  return (write(STDOUT_FILENO, &c, 1));
}

void save_cursor_position(void) {
  char buf[100];
  char *buffer;
  char *cap;
  char *str;

  buffer = buf;
  cap = tgetstr("sc", &buffer);
  if (cap == NULL)
	exit(1);
  str = tgoto(cap, 0, 0);
  if (str == NULL)
	exit(1);
  if (tputs(str, 1, ft_putint) == -1)
	exit(1);
}

void move_home(void) {
  char buf[100];
  char *buffer;
  char *cap;
  char *str;

  buffer = buf;
  cap = tgetstr("rc", &buffer);
  if (cap == NULL)
	exit(1);
  str = tgoto(cap, 0, 0);
  if (str == NULL)
	exit(1);
  if (tputs(str, 1, ft_putint) == -1)
	exit(1);
}

void move_end(int len) {
  char buf[100];
  char *buffer;
  char *cap;
  char *str;
  int i;

  i = 0;
  buffer = buf;
  move_home();
  while (i < len) {
	cap = tgetstr("nd", &buffer);
	if (cap == NULL)
	  exit(1);
	str = tgoto(cap, 0, 0);
	if (str == NULL)
	  exit(1);
	if (tputs(str, 1, ft_putint) == -1)
	  exit(1);
	buffer = buf;
	ft_bzero(buffer, 100);
	i++;
  }
}
