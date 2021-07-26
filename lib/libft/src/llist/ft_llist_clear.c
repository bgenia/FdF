#include "libft/llist.h"

void	ft_llist_clear(t_llist **list, void (*_free)(void*))
{
	t_llist	*current;
	t_llist	*next;

	current = *list;
	while (current)
	{
		next = current->next;
		ft_llist_free(current, _free);
		current = next;
	}
	*list = NULL;
}
