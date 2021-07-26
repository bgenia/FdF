#include "libft/memory.h"

void	*ft_reallocarray(void *ptr, size_t old_n, size_t new_n, size_t size)
{
	return (ft_realloc(ptr, old_n * size, new_n * size));
}
