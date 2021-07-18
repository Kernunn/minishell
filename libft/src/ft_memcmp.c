#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n) {
  size_t k;

  k = 0;
  while (((unsigned char *) s1)[k] == ((unsigned char *) s2)[k]
	  && k < n)
	k++;
  if (k == n)
	return (0);
  return ((int) (((unsigned char *) s1)[k] - ((unsigned char *) s2)[k]));
}
