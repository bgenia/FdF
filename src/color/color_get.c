#include "color.h"

t_color_component	color_get_alpha(t_color color)
{
	return ((color & (0xFF << 24)) >> 24);
}

t_color_component	color_get_red(t_color color)
{
	return ((color & (0xFF << 16)) >> 16);
}

t_color_component	color_get_green(t_color color)
{
	return ((color & (0xFF << 8)) >> 8);
}

t_color_component	color_get_blue(t_color color)
{
	return ((color & (0xFF << 0)) >> 0);
}
