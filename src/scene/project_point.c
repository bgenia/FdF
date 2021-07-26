#include <math.h>

#include "libft/tuples.h"

#include "scene.h"
#include "projection.h"
#include "matrix.h"

t_int2	project_point(t_int3 point, t_view view, double scale)
{
	t_matrix3x3	transformation;
	t_vector3	v1;
	t_vector3	v2;
	t_int2		result;

	v1[0] = (double)point.x + view.center_offset.x;
	v1[1] = (double)point.y + view.center_offset.y;
	v1[2] = (double)point.z + view.center_offset.z;
	rotation_matrix(view.angle, transformation);
	transform_vector(transformation, v1, v2);
	projection_matrix(view.projection, transformation);
	transform_vector(transformation, v2, v1);
	v1[0] += view.render_offset.x;
	v1[1] += view.render_offset.y;
	result.x = round(v1[0] * (scale + view.zoom));
	result.y = round(v1[1] * (scale + view.zoom));
	return (result);
}
