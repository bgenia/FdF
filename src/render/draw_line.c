#include <math.h>

#include <stdio.h>

#include "render.h"
#include "tuples.h"

static double	abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static double	get_step(double dx, double dy)
{
	if (abs(dx) >= abs(dy))
		return (abs(dx));
	else
		return (abs(dy));
}

void	draw_line(t_renderer *renderer, t_brush brush, t_line line)
{
	t_double2	position;
	t_double2	delta;
	double		step;
	int			i;
	t_color		color;

	delta.x = (line.b.x - line.a.x);
	delta.y = (line.b.y - line.a.y);
	step = get_step(delta.x, delta.y);
	delta.x /= step;
	delta.y /= step;
	position.x = line.a.x;
	position.y = line.a.y;
	i = 0;
	while (i < step)
	{
		color = gradient_get_color(brush.color, brush.color2, step, i);
		draw_pixel(renderer, color, int2(position.x, position.y));
		position.x += delta.x;
		position.y += delta.y;
		i++;
	}
}
