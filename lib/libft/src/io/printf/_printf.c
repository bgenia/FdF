#include <stdarg.h>
#include <unistd.h>

#include "libft/io.h"
#include "libft/utils.h"
#include "libft/string.h"

#include "libft/io/printf/placeholder.h"
#include "libft/io/printf/parser.h"
#include "libft/io/printf/printers.h"

static int	print_argument(const char **format, va_list *args, ssize_t *n)
{
	const char		*s;
	t_placeholder	*placeholder;

	s = *format;
	placeholder = parse_placeholder(format);
	if (!placeholder)
		return (0);
	if (placeholder->type == 0)
	{
		if (!ft_writeguard(write(STDOUT_FILENO, s, *format - s), n))
			return (ft_free1pass(placeholder, 0));
	}
	else if (placeholder->type & TYPE_PERCENT)
	{
		if (!ft_writeguard(ft_put_character(STDOUT_FILENO, '%'), n))
			return (ft_free1pass(placeholder, 0));
	}
	else
	{
		if (!print_value(placeholder, args, n))
			return (ft_free1pass(placeholder, 0));
	}
	return (ft_free1pass(placeholder, 1));
}

int	_printf(const char *format, va_list *args)
{
	ssize_t	n;
	int		length;
	char	*next;

	n = 0;
	while (*format)
	{
		next = ft_strchr(format, '%');
		if (!next)
			next = ft_strchr(format, '\0');
		length = next - format;
		if (!ft_writeguard(write(STDOUT_FILENO, format, length), &n))
			return (-1);
		format = next;
		if (*format == '%')
			if (!print_argument(&format, args, &n))
				return (-1);
	}
	return (n);
}
