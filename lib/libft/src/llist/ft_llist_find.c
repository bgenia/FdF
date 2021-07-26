#include "libft/llist.h"

t_llist	*ft_llist_find(t_llist *list, void *value, int (*comparator)())
{
	t_llist	*current_element;

	current_element = list;
	while (current_element)
	{
		if (comparator(current_element->value, value) == 0)
			return (current_element);
		current_element = current_element->next;
	}
	return (NULL);
}
