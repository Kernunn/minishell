#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include "heredoc_utils.h"

static char *ft_create_name(void) {
  static int k;
  char *num;
  char *name;

  num = ft_itoa(k);
  if (num == NULL)
	exit(1);
  name = ft_strjoin("/tmp/tmp", num);
  free(num);
  k++;
  return (name);
}

static int write_warning(char *end) {
  write(2, "warning: here-document delimited by end-of-file(wanted ", 56);
  write(2, "`", 1);
  write(2, end, ft_strlen(end));
  write(2, "'", 1);
  write(2, ")\n", 2);
  return (1);
}

static char *write_to_file(char *res, int quotes) {
  int fd;
  char *change_str;
  char *file_name;

  file_name = ft_create_name();
  change_str = ft_change_str(res, quotes);
  fd = open(file_name, O_TRUNC | O_CREAT | O_RDWR, 0644);
  write(fd, change_str, ft_strlen(change_str));
  close(fd);
  free(change_str);
  return (file_name);
}

char *here_doc(char *end, int quotes) {
  char *line;
  char *res;
  int k;
  char *tmp;

  res = ft_strdup("");
  write(2, "> ", 2);
  while ((k = get_next_line(1, &line)) >= 0) {
	if ((ft_strncmp(line, end, ft_strlen(end) + 1)) == 0)
	  break;
	tmp = res;
	res = ft_strjoin(res, line);
	if (k)
	  ft_add_elem_to_str(&res, "\n", 1);
	free(tmp);
	if (k == 0 && ft_strlen(line) == 0 && write_warning(end))
	  break;
	free(line);
	write(2, "> ", 2);
  }
  free(line);
  tmp = write_to_file(res, quotes);
  free(res);
  return (tmp);
}
