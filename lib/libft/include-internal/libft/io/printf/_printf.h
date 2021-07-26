#ifndef _PRINTF_H
# define _PRINTF_H

# include <stdarg.h>
# include <unistd.h>

ssize_t	_printf(const char *format, va_list *args);

#endif
