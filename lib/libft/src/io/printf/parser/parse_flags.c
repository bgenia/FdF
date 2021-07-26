#include "libft/string.h"

#include "libft/io/printf/placeholder.h"

void	parse_flags(const char **str, t_placeholder *placeholder)
{
	while (1)
	{
		if (ft_strncmp(*str, "-", 1) == 0)
			placeholder->flags |= FLAG_LEFT_ALIGN;
		else if (ft_strncmp(*str, "0", 1) == 0)
			placeholder->flags |= FLAG_ZERO_PAD;
		else if (ft_strncmp(*str, " ", 1) == 0)
			placeholder->flags |= FLAG_BLANK_PLUS;
		else if (ft_strncmp(*str, "+", 1) == 0)
			placeholder->flags |= FLAG_FORCE_SIGN;
		else if (ft_strncmp(*str, "#", 1) == 0)
			placeholder->flags |= FLAG_ALT_FORM;
		else
			break ;
		*str += 1;
	}
}
