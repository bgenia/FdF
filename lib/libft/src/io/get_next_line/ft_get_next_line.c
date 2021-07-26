#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "libft/io/get_next_line/get_next_line_utils.h"

#include "libft/io/get_next_line.h"
#include "libft/utils.h"

static char	*get_line(char *remainder)
{
	int		line_length;
	char	*line;

	line_length = gnl_linelen(remainder);
	line = malloc(sizeof(*line) * (line_length + 1));
	if (line)
	{
		line[line_length] = '\0';
		gnl_memcpy(line, remainder, line_length);
	}
	return (line);
}

static void	shift_state(char **remainder)
{
	int		line_length;
	int		content_length;
	int		new_length;
	char	*new_content;

	line_length = gnl_linelen(*remainder);
	content_length = gnl_strlen(*remainder);
	new_length = content_length - line_length;
	new_content = malloc(sizeof(*new_content) * (new_length));
	if (new_content)
		gnl_memcpy(new_content, (*remainder) + line_length + 1, new_length);
	free(*remainder);
	*remainder = new_content;
}

static int	malloc_buffer(char **buffer, size_t size)
{
	if (size <= 0)
		return (0);
	*buffer = malloc(sizeof(**buffer) * (size + 1));
	return (!!*buffer);
}

int	ft_get_next_line(int fd, char **line, char **remainder, size_t buffer_size)
{
	char		*buffer;
	int			bytes_read;

	if (!line || !malloc_buffer(&buffer, buffer_size))
		return (GNL_ERROR);
	if (buffer_size == ULONG_MAX)
		buffer_size -= 1;
	bytes_read = 1;
	while (!gnl_has_eol(*remainder) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, buffer_size);
		if (bytes_read == -1)
			return (ft_free1pass(buffer, GNL_ERROR));
		buffer[bytes_read] = '\0';
		if (!gnl_append(remainder, buffer))
			return (ft_free1pass(buffer, GNL_ERROR));
	}
	free(buffer);
	*line = get_line(*remainder);
	if (bytes_read == 0)
		return (GNL_EOF);
	shift_state(remainder);
	if (!*line || !*remainder)
		return (GNL_ERROR);
	return (GNL_LINE);
}
