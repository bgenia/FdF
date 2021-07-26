#include <stdlib.h>

#include "libft/memory.h"

void	*ft_free_array(void **arr, size_t size)
{
	ft_free_each(arr, size);
	free(arr);
	return (NULL);
}
