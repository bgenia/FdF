#ifndef FDF_H
# define FDF_H

# include "libft/tuples.h"

# include "heightmap.h"
# include "color.h"
# include "scene.h"

# define W_WIDTH	1200
# define W_HEIGHT	680

# define COLOR_LOW	0x0000FF
# define COLOR_HIGH	0xFF0000

double
compute_scale(t_heightmap map);

t_color
get_point_color(t_heightmap map, t_int3 point);

void
render_edge(t_scene scene, t_int3 a, t_int3 b);

void
render_scene(t_scene scene);

void
close_esc_hook(int key_code, t_scene *scene);

void
scene_controls_hook(int key_code, t_scene *scene);

void
projection_controls_hook(int key_code, t_scene *scene);

void
angle_controls_hook(int key_code, t_scene *scene);

#endif
