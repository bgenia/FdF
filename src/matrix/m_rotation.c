#include <math.h>

#include "matrix.h"

t_dmatrix	m_rotation(double angle)
{
	t_dmatrix	matrix;

	matrix.m = 3;
	matrix.n = 3;
	matrix.value = malloc(sizeof(*matrix.value) * matrix.m * matrix.n);
	matrix.value[0] = cos(angle);
	matrix.value[1] = -sin(angle);
	matrix.value[2] = 0;
	matrix.value[3] = sin(angle);
	matrix.value[4] = cos(angle);
	matrix.value[5] = 0;
	matrix.value[6] = 0;
	matrix.value[7] = 0;
	matrix.value[8] = 1;
	return (matrix);
}
