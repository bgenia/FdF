#ifndef HEIGHTMAP_H
# define HEIGHTMAP_H

# include "libft/tuples.h"

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
heightmap_create(void);
void
heightmap_free(t_heightmap *map);

int
heightmap_add_line(t_heightmap *map);
int
heightmap_add_point(t_heightmap *map, int z);

#endif
