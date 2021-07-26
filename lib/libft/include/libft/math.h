#ifndef MATH_H
# define MATH_H

# include <inttypes.h>

intmax_t
ft_min(intmax_t a, intmax_t b);

intmax_t
ft_max(intmax_t a, intmax_t b);

uintmax_t
ft_minu(uintmax_t a, uintmax_t b);

uintmax_t
ft_maxu(uintmax_t a, uintmax_t b);

float
ft_minf(float a, float b);

float
ft_maxf(float a, float b);

double
ft_mind(double a, double b);

double
ft_maxd(double a, double b);

intmax_t
ft_clamp(intmax_t n, intmax_t min, intmax_t max);

uintmax_t
ft_clampu(uintmax_t n, uintmax_t min, uintmax_t max);

float
ft_clampf(float n, float min, float max);

double
ft_clampd(double n, double min, double max);

intmax_t
ft_abs(intmax_t n);

float
ft_absf(float n);

double
ft_absd(double n);

#endif
