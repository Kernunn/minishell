#include "ft_getcwd.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <limits.h>
#include "ft_env.h"

extern int g_status;

void ft_pwd(void) {
  char *pwd;

  if (!(pwd = malloc((PATH_MAX + 1) * sizeof(char))))
	exit(1);
  if ((getcwd(pwd, PATH_MAX))) {
	write(1, pwd, ft_strlen(pwd));
	write(1, "\n", 1);
	free(pwd);
  } else {
	free(pwd);
	pwd = ft_var_of_key("PWD");
	write(1, pwd, ft_strlen(pwd));
	write(1, "\n", 1);
  }
  g_status = 0;
}
