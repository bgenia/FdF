#include <unistd.h>

#include "libft/string.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
