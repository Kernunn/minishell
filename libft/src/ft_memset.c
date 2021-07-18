#include "libft.h"

void *ft_memset(void *s, int c, size_t n) {
  size_t k;

  k = 0;
  while (k < n) {
	((unsigned char *) s)[k] = (unsigned char) c;
	k++;
  }
  return (s);
}
