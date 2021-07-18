#include "libft.h"
#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char)) {
  unsigned int i;
  char *map;

  if (!s)
	return (NULL);
  i = 0;
  map = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
  if (map) {
	while (*s) {
	  map[i] = f(i, *s);
	  s++;
	  i++;
	}
	map[i] = '\0';
	return (map);
  }
  return (NULL);
}
