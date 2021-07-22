#include "tuples.h"

t_double2	double2(double x, double y)
{
	return ((t_double2){.x = x, .y = y});
}

t_double3	double3(double x, double y, double z)
{
	return ((t_double3){.x = x, .y = y, .z = z});
}
