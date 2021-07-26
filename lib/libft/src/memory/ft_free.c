#include <stdlib.h>

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}
