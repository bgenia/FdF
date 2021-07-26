#include <unistd.h>

#include "libft/types.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t'
		|| c == '\v' || c == '\n'
		|| c == '\r' || c == '\f');
}

static long	add_digit(long value, int digit, int sign, int *overflow)
{
	long	result;

	result = value * 10 + (sign * digit);
	if (sign > 0 && result < 0)
	{
		*overflow = 1;
		result = (9223372036854775807L);
	}
	if (sign < 0 && result > 0)
	{
		*overflow = 1;
		result = -(9223372036854775807L) - 1L;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	value;
	int		overflow;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	value = 0;
	if (!ft_isdigit(str[i]))
		return (value);
	overflow = 0;
	while (ft_isdigit(str[i]) && !overflow)
	{
		value = add_digit(value, str[i] - '0', sign, &overflow);
		i++;
	}
	return ((int) value);
}
