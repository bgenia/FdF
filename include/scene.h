#ifndef SCENE_H
# define SCENE_H

# include "libft/tuples.h"

# include "projection.h"
# include "heightmap.h"
# include "render.h"

typedef struct s_view
{
	double			zoom;
	double			angle;
	t_double3		center_offset;
	t_double2		render_offset;
	t_projection	projection;
}
t_view;

typedef struct s_scene
{
	t_heightmap	map;
	t_view		view;
	t_renderer	renderer;
}
t_scene;

t_view
view_create(t_heightmap map, t_projection projection);

int
view_direction(t_view view);

t_scene
scene_create(t_heightmap map, t_view view, t_renderer renderer);

t_int2
project_point(t_int3 point, t_view view, double scale);

#endif
