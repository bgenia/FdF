#include "space.h"

static t_point3d	point(int x, int y, int z)
{
	return ((t_point3d){.x = x, .y = y, .z = z});
}

static void	i_vertical_edges(
	t_space3d *space,
	int y,
	void (*f)(t_point3d a, t_point3d b, void *p),
	void *p
)
{
	int	x;

	x = 0;
	while (x < space->width)
	{
		f(point(x, y, space->points[y][x]),
			point(x, y - 1, space->points[y - 1][x]), p);
		x++;
	}
}

static void	i_horizontal_edges(
	t_space3d *space,
	int y,
	void (*f)(t_point3d a, t_point3d b, void *p),
	void *p
)
{
	int	x;

	x = 0;
	while (x < space->width - 1)
	{
		f(point(x, y, space->points[y][x]),
			point(x + 1, y, space->points[y][x + 1]), p);
		x++;
	}
}

void	space3d_edges_foreach(
	t_space3d *space,
	void (*f)(t_point3d a, t_point3d b, void *p),
	void *p
)
{
	int	y;

	if (!space->points)
		return ;
	y = 0;
	while (y < space->height)
	{
		if (y > 0)
			i_vertical_edges(space, y, f, p);
		i_horizontal_edges(space, y, f, p);
		y++;
	}
}
