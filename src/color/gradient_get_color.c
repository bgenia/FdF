#include <math.h>

#include "color.h"

#include <stdio.h>

t_color	gradient_get_color(t_color from, t_color to, int step, int n)
{
	double	a;
	double	r;
	double	g;
	double	b;

	a = color_get_alpha(from) + ((double)n / (step + 1))
		* (color_get_alpha(to) - color_get_alpha(from));
	r = color_get_red(from) + ((double)n / (step + 1))
		* (color_get_red(to) - color_get_red(from));
	g = color_get_green(from) + ((double)n / (step + 1))
		* (color_get_green(to) - color_get_green(from));
	b = color_get_blue(from) + ((double)n / (step + 1))
		* (color_get_blue(to) - color_get_blue(from));
	return (color_argb(round(a), round(r), round(g), round(b)));
}
