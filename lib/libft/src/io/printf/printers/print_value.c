#include <stdarg.h>
#include <unistd.h>

#include "libft/io/printf/placeholder.h"
#include "libft/io/printf/printers.h"

int	print_value(t_placeholder *pl, va_list *args, ssize_t *n)
{
	if (pl->type & TYPE_C)
		return (print_character(args, n));
	if (pl->type & TYPE_S)
		return (print_string(args, n));
	if (pl->type & TYPE_DI)
		return (print_signed(args, n));
	if (pl->type & (TYPE_U | TYPE_XL | TYPE_XU))
		return (print_unsigned(pl, args, n));
	if (pl->type & TYPE_P)
		return (print_pointer(args, n));
	return (0);
}
