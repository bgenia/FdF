#ifndef PROJECTION_H
# define PROJECTION_H

# include "libft/tuples.h"

typedef struct s_projection
{
	t_double3	angle;
	t_double3	scale;
}
t_projection;

t_projection
projection_line(void);
t_projection
projection_isometric(void);

#endif
