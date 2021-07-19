#include "matrix.h"

t_matrix	matrix_init(int m, int n, double **value)
{
	t_matrix	matrix;

	matrix.m = m;
	matrix.n = n;
	matrix.value = value;
	return (matrix);
}
