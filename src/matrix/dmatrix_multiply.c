#include "matrix.h"

#include <stdio.h>

static void	mzero(t_dmatrix *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->m)
	{
		j = 0;
		while (j < m->n)
		{
			dmatrix_set(*m, i, j, 0);
			j++;
		}
		i++;
	}
}

static void	dmatrix_add(t_dmatrix result, int i, int j, double value)
{
	dmatrix_set(result, i, j, dmatrix_get(result, i, j) + value);
}

void	dmatrix_multiply(t_dmatrix a, t_dmatrix b, t_dmatrix *result)
{
	int		i;
	int		j;
	int		k;

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
				dmatrix_add(*result, i, j,
					dmatrix_get(a, i, k) * dmatrix_get(b, k, j));
				k++;
			}
			j++;
		}
		i++;
	}
}
