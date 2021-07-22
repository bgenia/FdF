#include <math.h>

#include "matrix.h"

t_dmatrix	m_isometric_projection(double z_scale)
{
	t_dmatrix	matrix;

	matrix.m = 2;
	matrix.n = 3;
	matrix.value = malloc(sizeof(*matrix.value) * matrix.m * matrix.n);
	matrix.value[0] = 2. / sqrt(5.);
	matrix.value[1] = -2. / sqrt(5.);
	matrix.value[2] = 0.;
	matrix.value[3] = 1. / sqrt(5.);
	matrix.value[4] = 1. / sqrt(5.);
	matrix.value[5] = -1 * z_scale;
	// matrix.value = (double []){
	// 	2. / sqrt(5.),
	// 	-2. / sqrt(5.),
	// 	0.,
	// 	1. / sqrt(5.),
	// 	1. / sqrt(5.),
	// 	1. * z_scale
	// };
	return (matrix);
}
