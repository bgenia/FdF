#include <stdlib.h>

#include "libft/io/printf/placeholder.h"
#include "libft/io/printf/parser.h"

t_placeholder	*parse_placeholder(const char **str)
{
	t_placeholder	*placeholder;

	placeholder = malloc(sizeof(*placeholder));
	if (!placeholder)
		return (NULL);
	placeholder->flags = 0;
	placeholder->type = 0;
	placeholder->width = -1;
	placeholder->precision = -1;
	*str += 1;
	parse_flags(str, placeholder);
	parse_width(str, placeholder);
	parse_precision(str, placeholder);
	parse_size(str, placeholder);
	parse_type(str, placeholder);
	if (placeholder->flags & FLAG_LEFT_ALIGN
		&& placeholder->flags & FLAG_ZERO_PAD)
		placeholder->flags -= FLAG_ZERO_PAD;
	if (placeholder->flags & FLAG_FORCE_SIGN
		&& placeholder->flags & FLAG_BLANK_PLUS)
		placeholder->flags -= FLAG_BLANK_PLUS;
	return (placeholder);
}
