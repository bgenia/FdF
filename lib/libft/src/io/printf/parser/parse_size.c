#include "libft/string.h"

#include "libft/io/printf/placeholder.h"

void	parse_size(const char **str, t_placeholder *placeholder)
{
	if (ft_strncmp(*str, "ll", 2) == 0)
	{
		placeholder->type |= TYPE_SIZE_LL;
		*str += 2;
	}
	else if (ft_strncmp(*str, "l", 1) == 0)
	{
		placeholder->type |= TYPE_SIZE_L;
		*str += 1;
	}
	else if (ft_strncmp(*str, "hh", 2) == 0)
	{
		placeholder->type |= TYPE_SIZE_HH;
		*str += 2;
	}
	else if (ft_strncmp(*str, "h", 1) == 0)
	{
		placeholder->type |= TYPE_SIZE_H;
		*str += 1;
	}
}
