#ifndef TYPES_H
# define TYPES_H

# include <unistd.h>

char
ft_basedigit(unsigned int n, unsigned int base);

int
ft_atoi(const char *str);

int
ft_isalpha(int c);

int
ft_isdigit(int c);

int
ft_isalnum(int c);

int
ft_isascii(int c);

int
ft_isprint(int c);

int
ft_toupper(int c);

int
ft_tolower(int c);

#endif
