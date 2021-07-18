#include "t_token.h"
#include <stdlib.h>
#include "libft.h"

extern char **g_env;
extern int g_status;

static char *search_in_env(char *name) {
  char *tmp;
  size_t name_len;
  char *value;
  int i;

  i = 0;
  value = NULL;
  name_len = ft_strlen(name);
  tmp = malloc((name_len + 2) * sizeof(char));
  ft_memcpy(tmp, name, name_len);
  tmp[name_len] = '=';
  tmp[name_len + 1] = '\0';
  while (g_env[i] != NULL) {
	if (!ft_strncmp(g_env[i], tmp, name_len + 1))
	  value = ft_substr(g_env[i], name_len + 1,
						ft_strlen(g_env[i]) - name_len - 1);
	i++;
  }
  free(tmp);
  return (value);
}

void parameter_expansion(t_token *token) {
  char *local_var;

  if (token->type == VAR_IN_DOUBLE_QUOTES || token->type == VAR) {
	if (!(ft_strncmp(token->str, "?", 2))) {
	  if (!(local_var = ft_itoa(g_status)))
		exit(1);
	} else
	  local_var = search_in_env(token->str);
	if (local_var == NULL)
	  if (!(local_var = ft_strdup("")))
		exit(1);
	free(token->str);
	token->str = local_var;
	if (token->type == VAR_IN_DOUBLE_QUOTES)
	  token->type = WORD_IN_DOUBLE_QUOTES;
	if (token->type == VAR)
	  token->type = WORD;
  }
}
