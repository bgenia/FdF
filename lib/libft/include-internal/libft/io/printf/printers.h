#ifndef PRINTERS_H
# define PRINTERS_H

# include <stdarg.h>
# include <unistd.h>

# include "placeholder.h"

int	print_value(t_placeholder *pl, va_list *args, ssize_t *n);

int	print_character(va_list *args, ssize_t *n);
int	print_string(va_list *args, ssize_t *n);
int	print_pointer(va_list *args, ssize_t *n);
int	print_signed(va_list *args, ssize_t *n);
int	print_unsigned(t_placeholder *ph, va_list *args, ssize_t *n);

#endif
