#include "libft/math.h"

#include "scene.h"
#include "projection.h"
#include "heightmap.h"

static double	compute_z_offset(t_heightmap map)
{
	double	offset;

	offset = 0;
	offset -= map.min_elevation;
	offset -= (double)(map.max_elevation - map.min_elevation) / 2;
	return (offset);
}

t_view	view_create(t_heightmap map, t_projection projection)
{
	t_view	view;

	view.angle = 0;
	view.zoom = 0;
	view.center_offset = double3(
			-(double)map.width / 2,
			-(double)map.height / 2,
			compute_z_offset(map)
			);
	view.render_offset = double2(0, 0);
	view.projection = projection;
	return (view);
}
