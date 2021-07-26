#ifndef MATRIX_H
# define MATRIX_H

# include "projection.h"

typedef double		t_vector3[3];

typedef t_vector3	t_matrix3x3[3];

void
transform_vector(t_matrix3x3 matrix, t_vector3 vector, t_vector3 result);

void
rotation_matrix(double angle, t_matrix3x3 matrix);
void
projection_matrix(t_projection projection, t_matrix3x3 matrix);

#endif
