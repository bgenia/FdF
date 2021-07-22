#include <math.h>
#include <stdlib.h>

#include "matrix.h"

t_dmatrix	m_vector(double x, double y, double z)
{
	t_dmatrix	matrix;

	matrix.m = 3;
	matrix.n = 1;
	matrix.value = malloc(sizeof(*matrix.value) * 3);
	matrix.value[0] = x;
	matrix.value[1] = y;
	matrix.value[2] = z;
	return (matrix);
}
