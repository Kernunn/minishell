#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle,
		size_t len)
{
	size_t		i;
	const char	*stop;

	stop = haystack + len;
	if (!needle[0])
		return ((char *)haystack);
	while (*haystack && haystack < stop)
	{
		i = 0;
		while (*haystack == needle[i] && *haystack && *needle
				&& i < len && haystack < stop)
		{
			haystack++;
			i++;
		}
		if (!needle[i])
			return ((char *)haystack - i);
		if (i == len)
			return (NULL);
		haystack = haystack - i + 1;
	}
	return (NULL);
}
