#include <math.h>

#include "libft/tuples.h"

#include "scene.h"
#include "fdf.h"

static int	_acheck(double angle, int a, int b)
{
	if (angle > -0.74 && angle <= 0.26)
		return (a);
	return (b);
}

static void	render_vertical_edges(t_scene scene, int y, double angle)
{
	int	x;
	int	y1;

	x = _acheck(angle, 0, scene.map.width - 1);
	while (x != _acheck(angle, scene.map.width - 1, -1))
	{
		y1 = y + _acheck(angle, -1, 1);
		render_edge(
			scene,
			int3(x, y, scene.map.points[y][x]),
			int3(x, y - 1, scene.map.points[y - 1][x])
			);
		x += _acheck(angle, 1, -1);
	}
}

static void	render_horizontal_edges(t_scene scene, int y, double angle)
{
	int	x;
	int	x1;

	x = _acheck(angle, 0, scene.map.width - 1);
	while (x != _acheck(angle, scene.map.width - 2, 0))
	{
		x1 = x + _acheck(angle, 1, -1);
		render_edge(
			scene,
			int3(x, y, scene.map.points[y][x]),
			int3(x1, y, scene.map.points[y][x1])
			);
		x += _acheck(angle, 1, -1);
	}
}

void	render_scene(t_scene scene)
{
	double	angle;
	int		y;

	angle = scene.view.angle / M_PI;
	if (!scene.map.points)
		return ;
	y = _acheck(angle, 0, scene.map.height - 1);
	while (y != _acheck(angle, scene.map.height - 1, 0))
	{
		if (y != _acheck(angle, 0, scene.map.height - 1))
			render_vertical_edges(scene, y, angle);
		render_horizontal_edges(scene, y, angle);
		y += _acheck(angle, 1, -1);
	}
}
