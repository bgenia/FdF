#include <unistd.h>

#include "libft/string.h"

ssize_t	ft_put_string(int fd, char *string)
{
	if (!string)
		return (write(fd, "(null)", 6));
	return (write(fd, string, ft_strlen(string)));
}
