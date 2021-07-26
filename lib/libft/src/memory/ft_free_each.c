#include <stdlib.h>

void	ft_free_each(void **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (arr && i < size)
	{
		free(arr[i]);
		i++;
	}
}
