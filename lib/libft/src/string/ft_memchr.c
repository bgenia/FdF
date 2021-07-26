#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*start;
	size_t			i;

	start = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (start[i] == (unsigned char)c)
			return (start + i);
		i++;
	}
	return (NULL);
}
