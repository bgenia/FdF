#include "heightmap.h"

void	heightmap_points_foreach(
	t_heightmap *map,
	void (*f)(t_heightmap *map, t_int3 point)
)
{
	int	x;
	int	y;

	if (!map->points)
		return ;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			f(map, (t_int3){.x = x, .y = y, .z = map->points[y][x]});
			x++;
		}
		y++;
	}
}
