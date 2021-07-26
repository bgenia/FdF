#include "libft/math.h"

#include "heightmap.h"

static double	_horizontal_scale(t_heightmap map)
{
	int		width;
	int		length;
	double	size;
	double	scale;

	width = map.width;
	length = map.height;
	size = ft_max(length, width);
	scale = -size / 2 + 40;
	return (scale);
}

static double	_vertical_scale(t_heightmap map)
{
	double	height;
	double	scale;

	height = ft_abs(map.max_elevation - map.min_elevation);
	scale = -(height - 6) * 0.6 + 30;
	return (scale);
}

double	compute_scale(t_heightmap map)
{
	double	scale;

	scale = ft_mind(_horizontal_scale(map), _vertical_scale(map));
	if (scale < 3)
		scale = 3;
	if (scale > 30)
		scale = 30;
	return (scale);
}
