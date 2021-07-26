#include <stdarg.h>
#include <unistd.h>

#include "libft/io/printf/placeholder.h"

#include "libft/io.h"

int	print_signed(va_list *args, ssize_t *n)
{
	int		value;
	ssize_t	result;

	value = va_arg(*args, int);
	result = ft_put_int(STDOUT_FILENO, value, 10);
	return (ft_writeguard(result, n));
}
