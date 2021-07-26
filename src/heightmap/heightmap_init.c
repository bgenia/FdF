#include <stdlib.h>

#include "heightmap.h"

t_heightmap	heightmap_create(void)
{
	t_heightmap	map;

	map.width = 0;
	map.height = 0;
	map.max_elevation = 0;
	map.min_elevation = 0;
	map.x = 0;
	map.y = 0;
	map.points = NULL;
	return (map);
}
