#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size) {
  size_t i;

  i = 0;
  while (dest[i] && i < size)
	i++;
  if (size != 0 && i != size) {
	while (i < size - 1 && *src)
	  dest[i++] = *src++;
	dest[i] = '\0';
  }
  while (*src++)
	i++;
  return (i);
}
