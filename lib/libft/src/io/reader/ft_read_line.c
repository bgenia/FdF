#include <stddef.h>

#include "libft/io/reader.h"
#include "libft/io/get_next_line.h"

static int	map_gnl_status(int status)
{
	if (status == GNL_ERROR)
		return (READER_ERROR);
	if (status == GNL_LINE)
		return (READER_LINE);
	if (status == GNL_EOF)
		return (READER_EOF);
	return (READER_EMPTY);
}

char	*ft_read_line(t_reader *reader)
{
	int		status;
	char	*line;

	line = NULL;
	status = ft_get_next_line(
			reader->fd,
			&line,
			&reader->remainder,
			reader->buffer_size
			);
	reader->status = map_gnl_status(status);
	return (line);
}
