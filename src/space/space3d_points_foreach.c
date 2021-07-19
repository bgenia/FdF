#include "space.h"

void	space3d_points_foreach(t_space3d *space, void (*f)(t_point3d point))
{
	int	x;
	int	y;

	if (!space->points)
		return ;
	y = 0;
	while (y < space->height)
	{
		x = 0;
		while (x < space->width)
		{
			f((t_point3d){.x = x, .y = y, .z = space->points[y][x]});
			x++;
		}
		y++;
	}
}
