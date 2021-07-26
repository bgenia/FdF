#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

# include <unistd.h>

int		gnl_append(char	**dest, char *src);
void	*gnl_memcpy(void *dst, const void *src, size_t n);
int		gnl_linelen(char *string);
size_t	gnl_strlen(char *string);
int		gnl_has_eol(char *string);

#endif
