#include <stdlib.h>

size_t	gnl_strlen(char *string)
{
	size_t	length;

	length = 0;
	while (string && string[length])
		length++;
	return (length);
}

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

int	gnl_append(char	**dest, char *src)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*result;

	s1_length = gnl_strlen(*dest);
	s2_length = gnl_strlen(src);
	result = malloc(sizeof(*result) * (s1_length + s2_length + 1));
	if (!result)
	{
		if (*dest)
			free(*dest);
		*dest = NULL;
		return (0);
	}
	if (*dest)
	{
		gnl_memcpy(result, *dest, s1_length);
		free(*dest);
	}
	if (src)
		gnl_memcpy(&result[s1_length], src, s2_length + 1);
	if (!*dest && !src)
		result[0] = '\0';
	*dest = result;
	return (1);
}

int	gnl_linelen(char *string)
{
	int	i;

	i = 0;
	while (string && string[i] && string[i] != '\n')
		i++;
	return (i);
}

int	gnl_has_eol(char *string)
{
	int	i;

	i = 0;
	while (string && string[i])
		if (string[i++] == '\n')
			return (1);
	return (0);
}
