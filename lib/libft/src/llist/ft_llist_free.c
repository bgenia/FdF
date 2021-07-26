#include <stdlib.h>

#include "libft/llist.h"

void	ft_llist_free(t_llist *list, void (*_free)(void*))
{
	if (list)
	{
		_free(list->value);
		free(list);
	}
}
