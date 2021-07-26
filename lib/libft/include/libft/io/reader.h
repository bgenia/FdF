#ifndef READER_H
# define READER_H

# include <stdlib.h>

typedef struct s_reader
{
	int		fd;
	char	*remainder;
	size_t	buffer_size;
	int		status;
}
t_reader;

# define READER_ERROR	-1
# define READER_EMPTY	0
# define READER_LINE	1
# define READER_EOF		2

# define READER_DEFAULT_BUFSIZE	32

t_reader
ft_reader_create(int fd, size_t buffer_size);
void
ft_reader_free(t_reader *reader);

char
*ft_read_line(t_reader *reader);
char
**ft_read_lines(t_reader *reader);
char
*ft_read_file(t_reader *reader);

#endif
