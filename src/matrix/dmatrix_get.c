#include "matrix.h"

double	dmatrix_get(t_dmatrix matrix, int i, int j)
{
	return (matrix.value[i * matrix.n + j]);
}
