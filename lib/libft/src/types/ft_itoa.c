#include <stdlib.h>

static int	get_digit_count(long n)
{
	int	digits;

	digits = 0;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static int	get_number_length(int n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (get_digit_count(-(long)n) + 1);
	return (get_digit_count(n));
}

static void	stringify_positive(char *s, long n, int length)
{
	if (n >= 10)
	{
		stringify_positive(s, n / 10, length - 1);
		stringify_positive(s, n % 10, length);
	}
	else
	{
		s[length - 1] = n + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;

	length = get_number_length(n);
	result = malloc(sizeof(*result) * (length + 1));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	if (n < 0)
		stringify_positive(&result[1], -(long)n, length - 1);
	else
		stringify_positive(result, n, length);
	result[length] = '\0';
	return (result);
}
