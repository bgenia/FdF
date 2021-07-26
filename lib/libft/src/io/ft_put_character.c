#include <unistd.h>

ssize_t	ft_put_character(int fd, char c)
{
	return (write(fd, &c, 1));
}
