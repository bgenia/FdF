#include "tuples.h"

t_int2	int2(int x, int y)
{
	return ((t_int2){.x = x, .y = y});
}

t_int3	int3(int x, int y, int z)
{
	return ((t_int3){.x = x, .y = y, .z = z});
}
