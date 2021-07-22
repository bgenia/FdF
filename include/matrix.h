#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_dmatrix
{
	int		m;
	int		n;
	double	*value;
}
t_dmatrix;

t_dmatrix
dmatrix_create(int m, int n, double *value);

double
dmatrix_get(t_dmatrix matrix, int i, int j);
void
dmatrix_set(t_dmatrix matrix, int i, int j, double value);

void
dmatrix_multiply(t_dmatrix a, t_dmatrix b, t_dmatrix *result);

t_dmatrix
m_isometric_projection(double z_scale);
t_dmatrix
m_vector(double x, double y, double z);
t_dmatrix
m_rotation(double angle);

#endif
