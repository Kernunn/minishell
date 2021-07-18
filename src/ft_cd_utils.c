#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "libft.h"
#include <string.h>
#include <limits.h>
#include "ft_env.h"

int ft_malloc(char **str, size_t buf_size) {
  *str = (char *) malloc(sizeof(char) * (buf_size + 1));
  if (!(*str))
	exit(1);
  return (1);
}

char *ft_getcwd(void) {
  char *str_dir;
  size_t buf_size;

  buf_size = PATH_MAX;
  ft_malloc(&str_dir, buf_size);
  if (getcwd(str_dir, buf_size) == NULL) {
	ft_putstr_fd("cd: error retrieving current directory: \
getcwd: cannot access parent directories: \
No such file or directory\n", 2);
	free(str_dir);
	str_dir = NULL;
  }
  return (str_dir);
}

int ft_error1_print(void) {
  write(2, "cd: ", 4);
  write(2, "too many arguments", 18);
  write(2, "\n", 1);
  return (1);
}

int ft_error2_print(char **argv) {
  write(2, "cd: ", 4);
  write(2, argv[0], ft_strlen(argv[0]));
  write(2, ": ", 2);
  write(2, strerror(errno), ft_strlen(strerror(errno)));
  write(2, "\n", 1);
  return (1);
}
