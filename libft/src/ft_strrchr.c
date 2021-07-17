#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	count;
	int		ans;

	count = 0;
	ans = -1;
	while (s[count])
	{
		if (s[count] == (unsigned char)c)
			ans = count;
		count++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + count);
	if (ans != -1)
		return ((char *)s + ans);
	return (NULL);
}
