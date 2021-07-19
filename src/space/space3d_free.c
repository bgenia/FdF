#include <stdlib.h>

#include "space.h"

void	space3d_free(t_space3d *space)
{
	int	row;

	row = 0;
	while (row < space->height)
	{
		free(space->points[row]);
		row++;
	}
	free(space->points);
}
