#include "matrix.h"

void	transform_vector(t_matrix3x3 matrix, t_vector3 vector, t_vector3 result)
{
	int		i;
	int		k;

	i = 0;
	while (i < 3)
		result[i++] = 0;
	i = 0;
	while (i < 3)
	{
		k = 0;
		while (k < 3)
		{
			result[i] += matrix[i][k] * vector[k];
			k++;
		}
		i++;
	}
}
