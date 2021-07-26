#include <stdarg.h>
#include <unistd.h>
#include <inttypes.h>

#include "libft/io.h"

#include "libft/io/printf/placeholder.h"

int	print_pointer(va_list *args, ssize_t *n)
{
	uint64_t	value;
	ssize_t		result;

	value = (uint64_t)va_arg(*args, void *);
	result = ft_putf_uint(STDOUT_FILENO, value, 16, (t_number_format){
			.prefix = "0x",
			.capitalize = 0
		});
	return (ft_writeguard(result, n));
}
