#include <inttypes.h>
#include "libft/math.h"

intmax_t	ft_clamp(intmax_t n, intmax_t min, intmax_t max)
{
	return (ft_min(min, ft_max(n, max)));
}

uintmax_t	ft_clampu(uintmax_t n, uintmax_t min, uintmax_t max)
{
	return (ft_minu(min, ft_maxu(n, max)));
}

float	ft_clampf(float n, float min, float max)
{
	return (ft_minf(min, ft_maxf(n, max)));
}

double	ft_clampd(double n, double min, double max)
{
	return (ft_mind(min, ft_maxd(n, max)));
}
