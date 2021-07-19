#include <math.h>

#include "matrix.h"

t_matrix	m_isometric_projection(double z_scale)
{
	t_matrix	matrix;

	matrix.m = 2;
	matrix.n = 3;
	matrix.value = (double **)(double [2][3]){
	{
		2. / sqrt(5.),
		-2. / sqrt(5.),
		0
	},
	{
		1. / sqrt(5.),
		1. / sqrt(5.),
		1. * z_scale
	}
	};
	return (matrix);
}
