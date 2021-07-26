#ifndef IO_H
# define IO_H

# include <unistd.h>
# include <inttypes.h>

int
ft_writeguard(ssize_t value, ssize_t *result);

ssize_t
ft_put_character(int fd, char c);
ssize_t
ft_put_string(int fd, char *string);
ssize_t
ft_put_line(int fd, char *line);

typedef struct s_number_format
{
	char	*prefix;
	char	*minus_sign;
	int		capitalize;
}	t_number_format;

ssize_t
ft_putf_uint(int fd, uint64_t n, uint32_t base, t_number_format format);
ssize_t
ft_putf_int(int fd, int64_t n, uint32_t base, t_number_format format);

ssize_t
ft_put_uint(int fd, uint64_t n, uint32_t base);
ssize_t
ft_put_int(int fd, int64_t n, uint32_t base);

#endif
