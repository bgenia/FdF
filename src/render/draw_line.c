#include <math.h>

#include "render.h"

void	draw_line(t_renderer *renderer, t_brush brush, t_spoint a, t_spoint b)
{
	double		tg;
	t_spoint	position;

	tg = (double)abs(a.y - b.y) / (double)abs(a.x - b.x);
	position = (t_spoint){.x = a.x, .y = a.y};
	while (position.x <= b.x && position.y <= b.y)
	{
		draw_pixel(renderer, brush, position);
		position.x += 1;
		position.y += tg;
	}
}
