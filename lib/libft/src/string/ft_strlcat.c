#include <unistd.h>

#include "libft/string.h"

static size_t	ft_strnlen(const char *str, size_t max_length)
{
	size_t	length;

	length = 0;
	while (*str++ && length < max_length)
		length++;
	return (length);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;

	dst_length = ft_strnlen(dst, dstsize);
	src_length = ft_strlen(src);
	if (dstsize == dst_length)
		return (dstsize + src_length);
	if (src_length < dstsize - dst_length)
	{
		ft_memcpy(&dst[dst_length], src, src_length + 1);
	}
	else
	{
		ft_memcpy(&dst[dst_length], src, dstsize - dst_length - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_length + src_length);
}
