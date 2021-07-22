#include "render.h"

t_brush	brush_solid(t_color color)
{
	return ((t_brush){.color = color, .color2 = color});
}

t_brush	brush_gradient(t_color from, t_color to)
{
	return ((t_brush){.color = from, .color2 = to});
}
