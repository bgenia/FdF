#include "libft/llist.h"

size_t	ft_llist_size(t_llist *list)
{
	size_t	size;
	t_llist	*e;

	size = 0;
	e = list;
	while (e)
	{
		e = e->next;
		size++;
	}
	return (size);
}
