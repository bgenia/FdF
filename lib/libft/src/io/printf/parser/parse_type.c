#include "libft/io/printf/placeholder.h"

t_type_field	char_to_type(char c)
{
	if (c == 'c')
		return (TYPE_C);
	if (c == 's')
		return (TYPE_S);
	if (c == 'p')
		return (TYPE_P);
	if (c == 'd' || c == 'i')
		return (TYPE_DI);
	if (c == 'u')
		return (TYPE_U);
	if (c == 'x')
		return (TYPE_XL);
	if (c == 'X')
		return (TYPE_XU);
	if (c == 'n')
		return (TYPE_N);
	if (c == 'f')
		return (TYPE_F);
	if (c == 'e')
		return (TYPE_E);
	if (c == 'g')
		return (TYPE_G);
	if (c == '%')
		return (TYPE_PERCENT);
	return (TYPE_INVALID);
}

void	parse_type(const char **str, t_placeholder *placeholder)
{
	placeholder->type |= char_to_type(**str);
	if (placeholder->type != TYPE_INVALID)
		*str += 1;
}
