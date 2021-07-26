#include <unistd.h>

int	ft_writeguard(ssize_t value, ssize_t *result)
{
	if (value == -1)
		*result = -1;
	else
		*result += value;
	return (*result != -1);
}
