#ifndef HEIGHTMAP_H
# define HEIGHTMAP_H

# include "tuples.h"

typedef struct s_heightmap
{
	int		width;
	int		height;
	int		max_elevation;
	int		min_elevation;
	int		x;
	int		y;
	int		**points;
}	t_heightmap;

t_heightmap
heightmap_init(void);
void
heightmap_free(t_heightmap *map);

int
heightmap_add_line(t_heightmap *map);
int
heightmap_add_point(t_heightmap *map, int z);

void
heightmap_points_foreach(
	t_heightmap *map,
	void (*f)(t_heightmap *map, t_int3 point)
	);
void
heightmap_edges_foreach(
	t_heightmap *map,
	void (*f)(t_heightmap *map, t_int3 a, t_int3 b, void *p),
	void *p
	);
void
heightmap_edges_rforeach(
	t_heightmap *map,
	void (*f)(t_heightmap *map, t_int3 a, t_int3 b, void *p),
	void *p
	);

#endif
