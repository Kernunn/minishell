#include "libft.h"
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len) {
  size_t i;
  size_t len_s;
  char *sub;

  if (!s)
	return (NULL);
  i = 0;
  len_s = ft_strlen(s);
  if (len_s < len + start)
	len = len_s - start;
  if (len_s <= start)
	len = 0;
  sub = (char *) malloc(sizeof(char) * len + 1);
  if (sub) {
	while (i < len && s[i + start]) {
	  sub[i] = s[i + start];
	  i++;
	}
	sub[i] = '\0';
	return (sub);
  }
  return (NULL);
}
