#include <stdlib.h>

#include "space.h"

t_space3d	space3d_init(void)
{
	t_space3d	space;

	space.width = 0;
	space.height = 0;
	space.max_elevation = 0;
	space.min_elevation = 0;
	space.x = 0;
	space.y = 0;
	space.points = NULL;
	return (space);
}
