#include "color.h"

t_color	color_argb(
	t_color_component a,
	t_color_component r,
	t_color_component g,
	t_color_component b
)
{
	t_color	color;

	color = 0;
	color += a << 24;
	color += r << 16;
	color += g << 8;
	color += b << 0;
	return (color);
}

t_color	color_rgb(
	t_color_component r,
	t_color_component g,
	t_color_component b
)
{
	return (color_argb(0, r, g, b));
}
