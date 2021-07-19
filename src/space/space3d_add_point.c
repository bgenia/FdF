#include "libft/memory.h"

#include "space.h"

#include <stdio.h>

int	space3d_add_point(t_space3d *space, int z)
{
	if (!space->points)
		if (!space3d_add_line(space))
			return (0);
	printf(">>>> BRUH: %d %p\n", space->y, space->points[space->y]);
	space->points[space->y] = ft_reallocarray(
			space->points[space->y],
			space->width,
			space->width + 1,
			sizeof(*space->points[space->y])
			);
	if (!space->points[space->y])
		return (0);
	space->width++;
	if (space->width > 1)
		space->x++;
	space->points[space->y][space->x] = z;
	return (1);
}