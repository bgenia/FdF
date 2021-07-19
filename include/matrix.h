#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_matrix
{
	int		m;
	int		n;
	double	**value;
}	t_matrix;

t_matrix	matrix_create(int m, int n, double **value);

void		matrix_multiply(t_matrix a, t_matrix b, t_matrix *result);

t_matrix	m_isometric_projection(double z_scale);
t_matrix	m_vector(double x, double y, double z);

#endif
