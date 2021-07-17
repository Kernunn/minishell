#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s1) > SIZE_MAX - ft_strlen(s2))
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new)
	{
		i = 0;
		k = 0;
		while (s1 && *s1)
			new[i++] = *s1++;
		while (s2 && *s2)
			new[i + k++] = *s2++;
		new[i + k] = '\0';
		return (new);
	}
	return (NULL);
}
