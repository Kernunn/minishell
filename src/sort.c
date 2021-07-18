#include "libft.h"
#include <stdlib.h>

int ft_alphabet_strcmp(char *str1, char *str2) {
  char *copy1;
  char *copy2;
  int i;
  int res;

  i = 0;
  copy1 = ft_strdup(str1);
  copy2 = ft_strdup(str2);
  while (copy1[i]) {
	copy1[i] = ft_tolower(copy1[i]);
	i++;
  }
  i = 0;
  while (copy2[i]) {
	copy2[i] = ft_tolower(copy2[i]);
	i++;
  }
  res = ft_strncmp(copy1, copy2, ft_strlen(copy1) + 1);
  free(copy1);
  free(copy2);
  return (res);
}
