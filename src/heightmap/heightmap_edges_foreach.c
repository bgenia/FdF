#include "libft/tuples.h"

#include "heightmap.h"

static void	i_vertical_edges(
	t_heightmap *map,
	int y,
	void (*f)(t_heightmap *map, t_int3 a, t_int3 b, void *args),
	void *args
)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		f(map, int3(x, y, map->points[y][x]),
			int3(x, y - 1, map->points[y - 1][x]), args);
		x++;
	}
}

static void	i_horizontal_edges(
	t_heightmap *map,
	int y,
	void (*f)(t_heightmap *map, t_int3 a, t_int3 b, void *args),
	void *args
)
{
	int	x;

	x = 0;
	while (x < map->width - 1)
	{
		f(map, int3(x, y, map->points[y][x]),
			int3(x + 1, y, map->points[y][x + 1]), args);
		x++;
	}
}

void	heightmap_edges_foreach(
	t_heightmap *map,
	void (*f)(t_heightmap *map, t_int3 a, t_int3 b, void *args),
	void *args
)
{
	int	y;

	if (!map->points)
		return ;
	y = 0;
	while (y < map->height)
	{
		if (y > 0)
			i_vertical_edges(map, y, f, args);
		i_horizontal_edges(map, y, f, args);
		y++;
	}
}
