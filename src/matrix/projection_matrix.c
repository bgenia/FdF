#include <math.h>

#include "projection.h"
#include "matrix.h"

void	projection_matrix(t_projection projection, t_matrix3x3 matrix)
{
	matrix[0][0] = cos(projection.angle.x) * projection.scale.x;
	matrix[0][1] = cos(projection.angle.y) * projection.scale.y;
	matrix[0][2] = cos(projection.angle.z) * projection.scale.z;
	matrix[1][0] = sin(projection.angle.x) * projection.scale.x;
	matrix[1][1] = sin(projection.angle.y) * projection.scale.y;
	matrix[1][2] = sin(projection.angle.z) * projection.scale.z;
	matrix[2][0] = 0.;
	matrix[2][1] = 0.;
	matrix[2][2] = 0.;
}
