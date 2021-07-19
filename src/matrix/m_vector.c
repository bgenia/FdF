#include <math.h>

#include "matrix.h"

t_matrix	m_vector(double x, double y, double z)
{
	t_matrix	matrix;

	matrix.m = 3;
	matrix.n = 1;
	matrix.value = (double **)(double [3][1]){
	{x},
	{y},
	{z}
	};
	return (matrix);
}
