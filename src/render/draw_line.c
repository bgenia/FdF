#include <math.h>

#include "render.h"

static int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	draw_line(t_renderer *renderer, t_brush brush, t_spoint a, t_spoint b)
{
	double	tg;
	double	x;
	double	y;

	tg = (double)abs(a.y - b.y) / (double)abs(a.x - b.x);
	x = a.x;
	y = a.y;
	while (x <= b.x && y <= b.y)
	{
		draw_pixel(
			renderer,
			brush,
			(t_spoint){.x = (int)floor(x), .y = (int)floor(y)}
			);
		x += 1;
		y += tg;
	}
}
