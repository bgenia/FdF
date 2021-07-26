#include <inttypes.h>

intmax_t	ft_abs(intmax_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}

float	ft_absf(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	ft_absd(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
