#include <stdlib.h>
#include <unistd.h>

#include "libft/string.h"
#include "libft/memory.h"

static size_t	size_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

static size_t	ft_strnlen(const char *str, size_t max_length)
{
	return (size_min(max_length, ft_strlen(str)));
}

char	*ft_substr(char const *str, unsigned int start, size_t length)
{
	size_t	substring_length;
	char	*substring;

	if (!str)
		return (ft_calloc(1, sizeof(char)));
	if (start > ft_strlen(str))
		substring_length = 0;
	else
		substring_length = ft_strnlen(&str[start], length);
	substring = malloc(sizeof(*substring) * substring_length + 1);
	if (!substring)
		return (NULL);
	ft_memcpy(substring, &str[start], substring_length);
	substring[substring_length] = '\0';
	return (substring);
}
