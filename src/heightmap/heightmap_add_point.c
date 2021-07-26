#include "libft/memory.h"

#include "heightmap.h"

#include <stdio.h>

int	heightmap_add_point(t_heightmap *map, int z)
{
	int	*temp_row;

	if (!map->points)
		if (!heightmap_add_line(map))
			return (0);
	temp_row = ft_reallocarray(
			map->points[map->y],
			map->width,
			map->width + 1,
			sizeof(*map->points[map->y])
			);
	if (!temp_row)
		return (0);
	map->points[map->y] = temp_row;
	map->width++;
	if (map->width > 1)
		map->x++;
	map->points[map->y][map->x] = z;
	if (z > map->max_elevation)
		map->max_elevation = z;
	if (z < map->min_elevation)
		map->min_elevation = z;
	return (1);
}
