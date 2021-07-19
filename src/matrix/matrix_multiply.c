#include "matrix.h"

static void	mzero(t_matrix *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->m)
	{
		j = 0;
		while (j < m->n)
		{
			m->value[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	matrix_multiply(t_matrix a, t_matrix b, t_matrix *result)
{
	int	i;
	int	j;
	int	k;

	result->m = a.m;
	result->n = b.n;
	mzero(result);
	i = 0;
	while (i < a.m)
	{
		j = 0;
		while (j < b.n)
		{
			k = 0;
			while (k < a.n)
			{
				result->value[i][j] += a.value[i][k] * b.value[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}
