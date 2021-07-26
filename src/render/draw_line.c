#include "libft/tuples.h"
#include "libft/math.h"

#include "render.h"

static double	get_step(double dx, double dy)
{
	if (ft_absd(dx) >= ft_absd(dy))
		return (ft_absd(dx));
	else
		return (ft_absd(dy));
}

void	draw_line(t_renderer *renderer, t_brush brush, t_int2 from, t_int2 to)
{
	t_double2	position;
	t_double2	delta;
	double		step;
	int			i;
	t_color		color;

	delta.x = (to.x - from.x);
	delta.y = (to.y - from.y);
	step = get_step(delta.x, delta.y);
	delta.x /= step;
	delta.y /= step;
	position.x = from.x;
	position.y = from.y;
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
