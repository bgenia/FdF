#include "libft/llist.h"

t_llist	*ft_llist_last(t_llist *list)
{
	t_llist	*last;

	last = list;
	while (last && last->next)
		last = last->next;
	return (last);
}
