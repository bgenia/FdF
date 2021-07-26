#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(size * count);
	if (!ptr)
		return (ptr);
	i = 0;
	while (i < size * count)
		ptr[i++] = 0;
	return (ptr);
}
