#include <stdlib.h>
#include <unistd.h>

#include "libft/io/reader.h"
#include "libft/string.h"

static void	read_file(
	t_reader *reader,
	char *buffer,
	char **result,
	ssize_t *bytes_read
)
{
	*bytes_read = read(reader->fd, buffer, reader->buffer_size);
	if (*bytes_read == 0)
		*result = ft_strdup("");
	while (*bytes_read > 0)
	{
		buffer[*bytes_read] = '\0';
		*result = ft_strjoin(*result, buffer);
		if (!*result)
			break ;
		*bytes_read = read(reader->fd, buffer, reader->buffer_size);
	}
}

char	*ft_read_file(t_reader *reader)
{
	char	*result;
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(*buffer) * (reader->buffer_size + 1));
	if (!buffer)
	{
		reader->status = READER_ERROR;
		return (NULL);
	}
	result = NULL;
	read_file(reader, buffer, &result, &bytes_read);
	free(buffer);
	if (bytes_read == -1 || !result)
	{
		free(result);
		reader->status = READER_ERROR;
	}
	else
	{
		reader->status = READER_EOF;
	}
	return (result);
}
