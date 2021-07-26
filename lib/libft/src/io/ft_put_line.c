#include "libft/io.h"

ssize_t	ft_put_line(int fd, char *line)
{
	ssize_t	result;

	result = 0;
	ft_writeguard(ft_put_string(fd, line), &result);
	ft_writeguard(ft_put_character(fd, '\n'), &result);
	return (result);
}
