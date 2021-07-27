#include "libft/tuples.h"
#include "libft/math.h"

#include "color.h"
#include "heightmap.h"
#include "fdf.h"

t_color	get_point_color(t_heightmap map, t_int3 point)
{
	t_color	color;

	color = gradient_get_color(
			COLOR_LOW,
			COLOR_HIGH,
			ft_max(0, ft_abs(map.max_elevation - map.min_elevation) - 1),
			point.z + ft_abs(map.min_elevation)
			);
	return (color);
}
