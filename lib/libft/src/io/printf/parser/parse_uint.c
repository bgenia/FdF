#include "libft/types.h"

unsigned int	parse_uint(const char **str)
{
	unsigned int	result;
	const char		*s;
	char			c;

	result = 0;
	s = *str;
	c = *s;
	while (ft_isdigit(c))
	{
		result *= 10;
		result += c - '0';
		c = *++s;
	}
	*str = s;
	return (result);
}
