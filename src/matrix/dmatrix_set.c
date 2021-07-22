#include "matrix.h"

void	dmatrix_set(t_dmatrix matrix, int i, int j, double value)
{
	matrix.value[i * matrix.n + j] = value;
}
