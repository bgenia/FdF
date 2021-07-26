#include <stdlib.h>
#include <unistd.h>

#include "libft/string.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	length;

	length = ft_strlen(str);
	copy = malloc(sizeof(*copy) * length + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, length + 1);
	return (copy);
}
