#include <termios.h>
#include <stdlib.h>
#include <term.h>

void init_term(int option) {
  static struct termios savetty;
  static struct termios tty;
  static char *termtype;

  if (option == 0) {
	termtype = getenv("TERM");
	if (termtype == NULL || tgetent(NULL, termtype) != 1)
	  exit(1);
	tcgetattr(0, &tty);
	savetty = tty;
	tty.c_lflag &= ~(ICANON | ECHO);
	tty.c_cc[VMIN] = 1;
	tcsetattr(0, TCSAFLUSH, &tty);
  } else
	tcsetattr(0, TCSAFLUSH, &savetty);
}
