#include <unistd.h>
#include <inttypes.h>

#include "libft/io.h"

ssize_t	ft_put_uint(int fd, uint64_t n, uint32_t base)
{
	t_number_format	format;

	format = (t_number_format){
		.capitalize = 0,
		.prefix = NULL
	};
	return (ft_putf_uint(fd, n, base, format));
}

ssize_t	ft_put_int(int fd, int64_t n, uint32_t base)
{
	t_number_format	format;

	format = (t_number_format){
		.capitalize = 0,
		.prefix = NULL,
		.minus_sign = "-"
	};
	return (ft_putf_int(fd, n, base, format));
}
