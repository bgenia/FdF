#include <stdarg.h>
#include <unistd.h>
#include <inttypes.h>

#include "libft/io.h"

#include "libft/io/printf/placeholder.h"

int	print_unsigned(t_placeholder *ph, va_list *args, ssize_t *n)
{
	uint32_t		value;
	ssize_t			result;
	int				base;
	t_number_format	format;

	value = va_arg(*args, uint32_t);
	if (ph->type & (TYPE_XL | TYPE_XU))
		base = 16;
	else
		base = 10;
	if (ph->type & TYPE_XU)
		format.capitalize = 1;
	else
		format.capitalize = 0;
	format.prefix = NULL;
	result = ft_putf_uint(STDOUT_FILENO, value, base, format);
	return (ft_writeguard(result, n));
}
