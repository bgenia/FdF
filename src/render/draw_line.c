#include <math.h>

#include "render.h"

static int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static double	direction(int a, int b)
{
	if (a > b)
		return (-1.);
	return (1.);
}

void	draw_line(t_renderer *renderer, t_brush brush, t_spoint a, t_spoint b)
{
	double	tg;
	double	x;
	double	y;

	tg = (double)abs(a.y - b.y) / (double)abs(a.x - b.x);
	x = a.x;
	y = a.y;
	while ((int)floor(x) != b.x || (int)floor(y) != b.y)
	{
		draw_pixel(
			renderer,
			brush,
			(t_spoint){.x = (int)floor(x), .y = (int)floor(y)}
			);
		if (tg < 1)
		{
			x += 1 * direction(a.x, b.x);
			y += tg * direction(a.y, b.y);
		}
		else
		{
			x += 1 / tg * direction(a.x, b.x);
			y += 1 * direction(a.y, b.y);
		}
	}
}
