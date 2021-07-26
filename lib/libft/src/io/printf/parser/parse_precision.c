#include "libft/io/printf/placeholder.h"
#include "libft/io/printf/parser.h"

void	parse_precision(const char **str, t_placeholder *placeholder)
{
	const char		*s;
	char			c;
	unsigned int	precision;

	s = *str;
	c = *s;
	if (c != '.')
		return ;
	c = *++s;
	if (c == '*')
	{
		placeholder->flags |= FLAG_ARG_PRECISION;
		c = *++s;
	}
	else
	{
		precision = parse_uint(&s);
		placeholder->precision = precision;
	}
	*str = s;
}
