#include <stdlib.h>

#include "heightmap.h"

void	heightmap_free(t_heightmap *map)
{
	int	row;

	row = 0;
	while (row < map->height)
	{
		free(map->points[row]);
		row++;
	}
	free(map->points);
}
