#include	<inttypes.h>

intmax_t	ft_min(intmax_t a, intmax_t b)
{
	if (a < b)
		return (a);
	return (b);
}

intmax_t	ft_max(intmax_t a, intmax_t b)
{
	if (a > b)
		return (a);
	return (b);
}

uintmax_t	ft_minu(uintmax_t a, uintmax_t b)
{
	if (a < b)
		return (a);
	return (b);
}

uintmax_t	ft_maxu(uintmax_t a, uintmax_t b)
{
	if (a > b)
		return (a);
	return (b);
}
