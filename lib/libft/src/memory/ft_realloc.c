#include <stdlib.h>

#include "libft/utils.h"
#include "libft/string.h"
#include "libft/math.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*result;

	result = NULL;
	if (new_size > 0)
	{
		result = malloc(new_size);
		if (result)
			ft_memcpy(result, ptr, ft_minu(old_size, new_size));
	}
	if (new_size == 0 || result)
		free(ptr);
	return (result);
}
