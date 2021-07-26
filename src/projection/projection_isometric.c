#include <math.h>

#include "projection.h"

t_projection	projection_isometric(void)
{
	t_projection	projection;

	projection = projection_line();
	projection.angle.x = M_PI / 6;
	projection.angle.y = M_PI / 6 * 5;
	projection.angle.z = -M_PI / 2;
	return (projection);
}
