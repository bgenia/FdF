#include <math.h>

#include "libft/string.h"

#include "projection.h"
#include "matrix.h"

t_dmatrix	projection_matrix(t_projection projection)
{
	double		*value;
	t_dmatrix	matrix;

	value = (double []){
		cos(projection.angle.x) * projection.scale.x,
		cos(projection.angle.y) * projection.scale.y,
		cos(projection.angle.z) * projection.scale.z,
		sin(projection.angle.x) * projection.scale.x,
		sin(projection.angle.y) * projection.scale.y,
		sin(projection.angle.z) * projection.scale.z
	};
	matrix = dmatrix_create(2, 3, malloc(sizeof(double) * 2 * 3));
	ft_memcpy(matrix.value, value, sizeof(double) * matrix.m * matrix.n);
	return (matrix);
}
