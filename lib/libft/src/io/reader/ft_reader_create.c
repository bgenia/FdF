#include <stddef.h>

#include "libft/io/reader.h"

t_reader	ft_reader_create(int fd, size_t buffer_size)
{
	t_reader	reader;

	reader.fd = fd;
	reader.buffer_size = buffer_size;
	reader.remainder = NULL;
	reader.status = READER_EMPTY;
	return (reader);
}
