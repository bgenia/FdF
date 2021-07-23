#ifndef PROJECTION_H
# define PROJECTION_H

# include "tuples.h"
# include "matrix.h"

typedef struct s_projection
{
	t_double3	angle;
	t_double3	scale;
}
t_projection;

t_dmatrix	projection_matrix(t_projection projection);

#endif
