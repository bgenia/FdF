#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define GNL_ERROR	-1
# define GNL_EOF	0
# define GNL_LINE	1

# include <unistd.h>

int
ft_get_next_line(int fd, char **line, char **remainder, size_t buffer_size);

#endif
