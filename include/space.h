#ifndef SPACE_H
# define SPACE_H

# include "tuples.h"

typedef struct s_space3d
{
	int		width;
	int		height;
	int		max_elevation;
	int		min_elevation;
	int		x;
	int		y;
	int		**points;
}	t_space3d;

t_space3d
space3d_init(void);
void
space3d_free(t_space3d *space);

int
space3d_add_line(t_space3d *space);
int
space3d_add_point(t_space3d *space, int z);

void
space3d_points_foreach(
	t_space3d *space,
	void (*f)(t_space3d *space, t_int3 point)
	);
void
space3d_edges_foreach(
	t_space3d *space,
	void (*f)(t_space3d *space, t_int3 a, t_int3 b, void *p),
	void *p
	);

#endif
