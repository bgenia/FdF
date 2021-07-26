#include "libft/tuples.h"

#include "scene.h"
#include "fdf.h"

static void	render_vertical_edges(t_scene scene, int y)
{
	int	x;

	x = 0;
	while (x < scene.map.width)
	{
		render_edge(
			scene,
			int3(x, y, scene.map.points[y][x]),
			int3(x, y - 1, scene.map.points[y - 1][x])
			);
		x++;
	}
}

static void	render_horizontal_edges(t_scene scene, int y)
{
	int	x;

	x = 0;
	while (x < scene.map.width - 1)
	{
		render_edge(
			scene,
			int3(x, y, scene.map.points[y][x]),
			int3(x + 1, y, scene.map.points[y][x + 1])
			);
		x++;
	}
}

void	render_scene(t_scene scene)
{
	int	y;

	if (!scene.map.points)
		return ;
	y = 0;
	while (y < scene.map.height)
	{
		if (y > 0)
			render_vertical_edges(scene, y);
		render_horizontal_edges(scene, y);
		y++;
	}
}
