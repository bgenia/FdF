#include "projection.h"

t_projection	projection_line(void)
{
	t_projection	projection;

	projection.angle.x = 0;
	projection.angle.y = 0;
	projection.angle.z = 0;
	projection.scale.x = 1;
	projection.scale.y = 1;
	projection.scale.z = 1;
	return (projection);
}
