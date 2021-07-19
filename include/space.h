#ifndef SPACE_H
# define SPACE_H

typedef struct s_space3d
{
	int		width;
	int		height;
	int		x;
	int		y;
	int		**points;
}	t_space3d;

typedef struct s_point3d
{
	int	x;
	int	y;
	int	z;
}	t_point3d;

t_space3d	space3d_init(void);
void		space3d_free(t_space3d *space);

int			space3d_add_line(t_space3d *space);
int			space3d_add_point(t_space3d *space, int z);

void		space3d_points_foreach(
				t_space3d *space,
				void (*f)(t_point3d point)
				);
void		space3d_edges_foreach(
				t_space3d *space,
				void (*f)(t_point3d a, t_point3d b, void *p),
				void *p
				);

#endif
