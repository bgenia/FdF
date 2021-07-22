#include "matrix.h"

t_dmatrix	dmatrix_create(int m, int n, double *value)
{
	t_dmatrix	matrix;

	matrix.m = m;
	matrix.n = n;
	matrix.value = value;
	return (matrix);
}
