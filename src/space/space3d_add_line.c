#include <stdlib.h>

#include "libft/memory.h"

#include "space.h"

int	space3d_add_line(t_space3d *space)
{
	space->points = ft_reallocarray(
			space->points,
			space->height,
			space->height + 1,
			sizeof(*space->points)
			);
	if (!space->points)
		return (0);
	space->height++;
	if (space->height > 1)
		space->y++;
	space->x = 0;
	space->width = 0;
	space->points[space->y] = NULL;
	return (1);
}
