#ifndef TUPLES_H
# define TUPLES_H

typedef struct s_int2
{
	int	x;
	int	y;
}
t_int2;

typedef struct s_int3
{
	int	x;
	int	y;
	int	z;
}
t_int3;

typedef struct s_int4
{
	int	w;
	int	x;
	int	y;
	int	z;
}
t_int4;

typedef struct s_double2
{
	double	x;
	double	y;
}
t_double2;

typedef struct s_double3
{
	double	x;
	double	y;
	double	z;
}
t_double3;

typedef struct s_double4
{
	double	w;
	double	x;
	double	y;
	double	z;
}
t_double4;

t_int2
int2(int x, int y);

t_int3
int3(int x, int y, int z);

t_int4
int4(int w, int x, int y, int z);

t_double2
double2(double x, double y);

t_double3
double3(double x, double y, double z);

t_double4
double4(double w, double x, double y, double z);

#endif
