#include "space.h"

void	space3d_points_foreach(
	t_space3d *space,
	void (*f)(t_space3d *space, t_int3 point)
)
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
			f(space, (t_int3){.x = x, .y = y, .z = space->points[y][x]});
			x++;
		}
		y++;
	}
}
