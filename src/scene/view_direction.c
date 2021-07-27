#include <math.h>

#include "scene.h"

int	view_direction(t_view view)
{
	double	angle;

	angle = view.angle / M_PI;
	return (angle > -0.74 && angle <= 0.26);
}
