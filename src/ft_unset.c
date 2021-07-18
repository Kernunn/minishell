#include "ft_check_key.h"
#include "ft_search_env.h"
#include <stdlib.h>
#include "libft.h"

extern int g_status;
extern char **g_env;
extern char **g_env_export;

static void ft_unset_key_export(char *key, int i) {
  int j;

  j = 0;
  if (i > -1)
	return;
  while (g_env_export && g_env_export[j]) {
	if ((ft_strncmp(g_env_export[j], key, ft_strlen(key) + 1)) == 0) {
	  free(g_env_export[j]);
	  g_env_export[j] = g_env_export[j + 1];
	  while (g_env_export[j]) {
		g_env_export[j] = g_env_export[j + 1];
		j++;
	  }
	} else
	  j++;
  }
}

void ft_unset(char **arg) {
  char *key;
  int i;

  g_status = 0;
  while (*arg) {
	key = *arg;
	if (!ft_check_key(key, "unset")) {
	  i = ft_search_env(key);
	  if (i > -1) {
		free(g_env[i]);
		g_env[i] = NULL;
		g_env[i] = g_env[i + 1];
		while (g_env[i]) {
		  g_env[i] = g_env[i + 1];
		  i++;
		}
	  }
	  ft_unset_key_export(key, i);
	}
	arg++;
  }
}
