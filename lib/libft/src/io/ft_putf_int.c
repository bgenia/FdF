#include <unistd.h>
#include <inttypes.h>

#include "libft/types.h"
#include "libft/io.h"
#include "libft/string.h"

static ssize_t	put_digit(uint32_t digit, int capitalize)
{
	char	character;

	character = ft_basedigit(digit, 16);
	if (capitalize)
		character = ft_toupper(character);
	return (write(STDOUT_FILENO, &character, 1));
}

static int	store_res(ssize_t *result_ptr, ssize_t value)
{
	if (value > 0)
		*result_ptr += value;
	return (value != -1);
}

ssize_t	ft_putf_uint(int fd, uint64_t n, uint32_t base, t_number_format format)
{
	ssize_t	result;

	result = 0;
	if (format.prefix)
	{
		ft_put_string(STDOUT_FILENO, format.prefix);
		result += ft_strlen(format.prefix);
	}
	if (n >= base)
	{
		format.prefix = NULL;
		if (!store_res(&result, ft_putf_uint(fd, n / base, base, format)))
			return (-1);
		if (!store_res(&result, ft_putf_uint(fd, n % base, base, format)))
			return (-1);
	}
	else
	{
		if (!store_res(&result, put_digit(n, format.capitalize)))
			return (-1);
	}
	return (result);
}

ssize_t	ft_putf_int(int fd, int64_t n, uint32_t base, t_number_format format)
{
	if (n < 0)
	{
		format.prefix = format.minus_sign;
		return (ft_putf_uint(fd, ~(uint64_t)n + 1, base, format));
	}
	return (ft_putf_uint(fd, n, base, format));
}
