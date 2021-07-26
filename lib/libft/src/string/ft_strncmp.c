#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (s1[i] && s2[i] && i < n && a[i] == b[i])
		i++;
	if (i == n)
		return (0);
	return (a[i] - b[i]);
}
