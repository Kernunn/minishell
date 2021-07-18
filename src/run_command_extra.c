#include <fcntl.h>
#include <unistd.h>
#include "t_command.h"
#include "ft_error.h"
#include "stdlib.h"

static void duplicate_fd(int pipe[2], int option) {
  dup2(pipe[option], option);
  close(pipe[0]);
  close(pipe[1]);
}

static void duplicate_fd2(int fd, int option, char *file_name) {
  if (fd != -1) {
	dup2(fd, option);
	close(fd);
  } else {
	print_errno(file_name);
	exit(1);
  }
}

void redirection_input(t_list *list, int lpipe[2]) {
  int fd;
  t_redirection *red;

  if (!list)
	duplicate_fd(lpipe, 0);
  else {
	fd = 0;
	while (list->next) {
	  red = list->content;
	  if ((fd = open(red->file_name, O_RDONLY)) == -1)
		break;
	  close(fd);
	  list = list->next;
	}
	red = list->content;
	if (fd != -1)
	  fd = open(red->file_name, O_RDONLY);
	duplicate_fd2(fd, 0, red->file_name);
  }
}

static int open_with_if(t_type type, char *file_name) {
  if (type == GREATGREAT)
	return (open(file_name, O_CREAT | O_APPEND | O_WRONLY, 0644));
  else
	return (open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644));
}

void redirection_output(t_list *list, int rpipe[2]) {
  int fd;
  t_redirection *red;

  if (!list)
	duplicate_fd(rpipe, 1);
  else {
	fd = 0;
	while (list->next) {
	  red = list->content;
	  if ((fd = open_with_if(red->type_of_redirection, red->file_name))
		  == -1)
		break;
	  close(fd);
	  list = list->next;
	}
	red = list->content;
	if (fd != -1)
	  fd = open_with_if(red->type_of_redirection, red->file_name);
	duplicate_fd2(fd, 1, red->file_name);
  }
}
