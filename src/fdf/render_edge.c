#include "libft/math.h"
#include "libft/tuples.h"

#include "heightmap.h"
#include "scene.h"
#include "fdf.h"

void	render_edge(t_scene scene, t_int3 a, t_int3 b)
{
	t_int2	proj_a;
	t_int2	proj_b;
	int		scale;

	scale = compute_scale(scene.map);
	proj_a = project_point(a, scene.view, scale);
	proj_b = project_point(b, scene.view, scale);
	proj_a.x += scene.renderer.width / 2;
	proj_b.x += scene.renderer.width / 2;
	proj_a.y += scene.renderer.height / 2;
	proj_b.y += scene.renderer.height / 2;
	draw_line(
		&scene.renderer,
		brush_gradient(
			get_point_color(scene.map, a),
			get_point_color(scene.map, b)
			),
		proj_a,
		proj_b
		);
}
