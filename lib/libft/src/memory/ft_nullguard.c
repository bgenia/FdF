#include <stdlib.h>

int	ft_nullguard(void *ptr, void **var)
{
	if (!ptr)
		return (0);
	*var = ptr;
	return (1);
}
