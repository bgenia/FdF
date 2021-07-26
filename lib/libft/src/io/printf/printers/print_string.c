#include <stdarg.h>
#include <unistd.h>

#include "libft/io.h"

#include "libft/io/printf/placeholder.h"

int	print_string(va_list *args, ssize_t *n)
{
	char	*value;
	ssize_t	result;

	value = va_arg(*args, char *);
	result = ft_put_string(STDOUT_FILENO, value);
	return (ft_writeguard(result, n));
}
