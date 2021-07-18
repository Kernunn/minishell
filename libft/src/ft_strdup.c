#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s) {
  size_t len;
  char *dup;

  len = ft_strlen(s);
  if ((dup = (char *) malloc(sizeof(char) * len + 1)))
	if (ft_strlcpy(dup, s, len + 1) == len)
	  return (dup);
  return (NULL);
}
