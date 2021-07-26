#include "libft/io/printf/placeholder.h"
#include "libft/io/printf/parser.h"

void	parse_width(const char **str, t_placeholder *placeholder)
{
	const char		*s;
	char			c;
	unsigned int	width;

	s = *str;
	c = *s;
	if (c == '*')
	{
		placeholder->flags |= FLAG_ARG_WIDTH;
		c = *++s;
	}
	else
	{
		width = parse_uint(&s);
		placeholder->width = width;
	}
	*str = s;
}
