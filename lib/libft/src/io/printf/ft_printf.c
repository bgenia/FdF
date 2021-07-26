#include <stdarg.h>
#include <unistd.h>

#include "libft/io/printf/_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	ssize_t		result;

	if (!format)
		return (-1);
	va_start(args, format);
	result = _printf(format, &args);
	va_end(args);
	return (result);
}
