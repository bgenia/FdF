#include "libft/llist.h"

void	ft_llist_add_front(t_llist **list, t_llist *element)
{
	element->next = *list;
	*list = element;
}
