#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t k;

	k = 0;
	while (k < n && ((unsigned char *)s)[k] != (unsigned char)c)
		k++;
	if (k == n)
		return (NULL);
	return ((void *)s + k);
}
