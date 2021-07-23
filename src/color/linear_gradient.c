#include "color.h"

t_color	linear_gradient(t_color colors[], int scales[], int n)
{
	int	i;

	i = 0;
	while (n > scales[i])
	{
		n -= scales[i];
		i++;
	}
	return (gradient_get_color(colors[i], colors[i + 1], scales[i], n));
}
