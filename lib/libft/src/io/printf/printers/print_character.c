#include <stdarg.h>
#include <unistd.h>

#include "libft/io.h"

#include "libft/io/printf/placeholder.h"

int	print_character(va_list *args, ssize_t *n)
{
	char	value;
	ssize_t	result;

	value = va_arg(*args, int);
	result = ft_put_character(STDOUT_FILENO, (char)value);
	return (ft_writeguard(result, n));
}
