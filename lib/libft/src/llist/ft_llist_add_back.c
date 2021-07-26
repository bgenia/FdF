#include "libft/llist.h"

void	ft_llist_add_back(t_llist **list, t_llist *element)
{
	t_llist	*last;

	last = ft_llist_last(*list);
	if (!last)
		*list = element;
	else
		last->next = element;
}
