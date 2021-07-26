#include "libft/llist.h"

void	ft_llist_insert_after(t_llist *list, t_llist *element)
{
	t_llist	*temp_element;

	temp_element = list->next;
	list->next = element;
	element->next = temp_element;
}
