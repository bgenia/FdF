#ifndef MAIN_COMMON_H
# define MAIN_COMMON_H

# include "libft/tuples.h"

# include "heightmap.h"
# include "color.h"
# include "scene.h"

# define W_WIDTH	1200
# define W_HEIGHT	680

double	compute_scale(t_heightmap *map);
t_color	get_point_color(t_heightmap *map, t_int3 point);
void	render_edge(t_heightmap *map, t_int3 a, t_int3 b, t_scene *scene);

#endif
