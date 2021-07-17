#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t count;

	count = 0;
	while (s[count] && ((unsigned char *)s)[count] != (unsigned char)c)
		count++;
	if (s[count] || (unsigned char)c == '\0')
		return ((char *)s + count);
	else
		return (NULL);
}
