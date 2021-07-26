#include "libft/math.h"
#include "libft/tuples.h"

#include "heightmap.h"
#include "color.h"
#include "scene.h"

static double	_horizontal_scale(t_heightmap *map)
{
	int		width;
	int		length;
	double	size;
	double	scale;

	width = map->width;
	length = map->height;
	size = ft_max(length, width);
	scale = -size / 2 + 40;
	return (scale);
}

static double	_vertical_scale(t_heightmap *map)
{
	double	height;
	double	scale;

	height = ft_abs(map->max_elevation - map->min_elevation);
	scale = -(height - 6) * 0.6 + 30;
	return (scale);
}

double	compute_scale(t_heightmap *map)
{
	double	scale;

	scale = ft_mind(_horizontal_scale(map), _vertical_scale(map));
	if (scale < 3)
		scale = 3;
	if (scale > 30)
		scale = 30;
	return (scale);
}

t_color	get_point_color(t_heightmap *map, t_int3 point)
{
	return (
		gradient_get_color(
			0x0000FF,
			0xFF0000,
			ft_abs(map->max_elevation - map->min_elevation),
			point.z - ft_abs(map->min_elevation)
		)
	);
}

void	render_edge(t_heightmap *map, t_int3 a, t_int3 b, t_scene *scene)
{
	t_int2	proj_a;
	t_int2	proj_b;
	int		scale;

	scale = compute_scale(map);
	proj_a = project_point(a, scene->view, scale);
	proj_b = project_point(b, scene->view, scale);
	proj_a.x += scene->renderer.width / 2;
	proj_b.x += scene->renderer.width / 2;
	proj_a.y += scene->renderer.height / 2;
	proj_b.y += scene->renderer.height / 2;
	draw_line(
		&scene->renderer,
		brush_gradient(
			get_point_color(map, a),
			get_point_color(map, b)
			),
		proj_a,
		proj_b
		);
}
