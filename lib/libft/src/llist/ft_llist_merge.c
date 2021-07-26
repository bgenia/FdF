#include "libft/llist.h"

void	ft_llist_merge(t_llist **list1, t_llist *list2)
{
	t_llist	*current_element;

	current_element = *list1;
	while (current_element && current_element->next)
		current_element = current_element->next;
	if (!current_element)
		*list1 = list2;
	else
		current_element->next = list2;
}
