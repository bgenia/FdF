#include <math.h>

#include "matrix.h"

void	rotation_matrix(double angle, t_matrix3x3 matrix)
{
	matrix[0][0] = cos(angle);
	matrix[0][1] = -sin(angle);
	matrix[0][2] = 0;
	matrix[1][0] = sin(angle);
	matrix[1][1] = cos(angle);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
}
