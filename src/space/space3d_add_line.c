#include <stdlib.h>

#include "libft/memory.h"

#include "heightmap.h"

int	heightmap_add_line(t_heightmap *map)
{
	map->points = ft_reallocarray(
			map->points,
			map->height,
			map->height + 1,
			sizeof(*map->points)
			);
	if (!map->points)
		return (0);
	map->height++;
	if (map->height > 1)
		map->y++;
	map->x = 0;
	map->width = 0;
	map->points[map->y] = NULL;
	return (1);
}
