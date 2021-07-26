#include <stddef.h>

#include "libft/io/reader.h"
#include "libft/memory.h"

static void	handle_eof(t_reader *reader, char *line, char ***lines, int i)
{
	char	**temp_lines;

	if (reader->status == READER_EOF)
	{
		(*lines)[i - 1] = line;
		temp_lines = ft_reallocarray(*lines, i, i + 1, sizeof(**lines));
		if (!temp_lines)
			reader->status = READER_ERROR;
		else
			*lines = temp_lines;
	}
}

static int	read_lines(t_reader *reader, char ***lines)
{
	char	**temp_lines;
	char	*line;
	int		i;

	i = 1;
	line = ft_read_line(reader);
	while (reader->status == READER_EMPTY || reader->status == READER_LINE)
	{
		temp_lines = ft_reallocarray(*lines, i, i + 1, sizeof(**lines));
		if (!temp_lines)
		{
			reader->status = READER_ERROR;
			break ;
		}
		*lines = temp_lines;
		(*lines)[i - 1] = line;
		line = ft_read_line(reader);
		i++;
	}
	handle_eof(reader, line, lines, i);
	return (i);
}

char	**ft_read_lines(t_reader *reader)
{
	char	**lines;
	int		line_count;

	lines = malloc(sizeof(*lines) * 1);
	if (!lines)
	{
		reader->status = READER_ERROR;
		return (NULL);
	}
	line_count = read_lines(reader, &lines);
	if (reader->status == READER_ERROR)
	{
		ft_free_array((void **)lines, line_count);
		return (NULL);
	}
	lines[line_count] = NULL;
	return (lines);
}
