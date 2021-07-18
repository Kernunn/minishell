#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size) {
  size_t i;

  if (!dest || !src)
	return (0);
  i = 0;
  if (size != 0) {
	while (i < size - 1 && *src)
	  dest[i++] = *src++;
	dest[i] = '\0';
  }
  while (*src++)
	i++;
  return (i);
}
