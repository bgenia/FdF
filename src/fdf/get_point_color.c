#include "libft/tuples.h"
#include "libft/math.h"

#include "color.h"
#include "heightmap.h"
#include "fdf.h"

t_color	get_point_color(t_heightmap map, t_int3 point)
{
	return (
		gradient_get_color(
			COLOR_LOW,
			COLOR_HIGH,
			ft_abs(map.max_elevation - map.min_elevation),
			point.z - ft_abs(map.min_elevation)
		)
	);
}
