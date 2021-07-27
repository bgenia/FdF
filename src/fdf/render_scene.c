#include <math.h>

#include "libft/tuples.h"

#include "scene.h"
#include "fdf.h"

static void	_rv_origin(t_scene scene, int y)
{
	int	x;
	int	y1;

	x = 0;
	while (x < scene.map.width)
	{
		y1 = y - 1;
		render_edge(
			scene,
			int3(x, y, scene.map.points[y][x]),
			int3(x, y1, scene.map.points[y1][x])
			);
		x += 1;
	}
}

static void	_rv_reverse(t_scene scene, int y)
{
	int	x;
	int	y1;

	x = scene.map.width - 1;
	while (x >= 0)
	{
		y1 = y + 1;
		render_edge(
			scene,
			int3(x, y, scene.map.points[y][x]),
			int3(x, y1, scene.map.points[y1][x])
			);
		x -= 1;
	}
}

static void	_rh_origin(t_scene scene, int y)
{
	int	x;
	int	x1;

	x = 0;
	while (x < scene.map.width - 1)
	{
		x1 = x + 1;
		render_edge(
			scene,
			int3(x, y, scene.map.points[y][x]),
			int3(x1, y, scene.map.points[y][x1])
			);
		x += 1;
	}
}

static void	_rh_reverse(t_scene scene, int y)
{
	int	x;
	int	x1;

	x = scene.map.width - 1;
	while (x >= 1)
	{
		x1 = x - 1;
		render_edge(
			scene,
			int3(x, y, scene.map.points[y][x]),
			int3(x1, y, scene.map.points[y][x1])
			);
		x -= 1;
	}
}

void	render_scene(t_scene scene)
{
	int		y;

	if (view_direction(scene.view) == 1)
	{
		y = 0;
		while (y < scene.map.height)
		{
			if (y > 0)
				_rv_origin(scene, y);
			_rh_origin(scene, y);
			y += 1;
		}
	}
	else
	{
		y = scene.map.height - 1;
		while (y >= 0)
		{
			if (y < scene.map.height - 1)
				_rv_reverse(scene, y);
			_rh_reverse(scene, y);
			y -= 1;
		}
	}
}
