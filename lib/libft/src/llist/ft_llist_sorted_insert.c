#include "libft/llist.h"

void	ft_llist_sorted_insert(t_llist **list, void *value, int (*comparator)())
{
	t_llist	*element;
	t_llist	*prev_element;
	t_llist	*current_element;

	element = ft_llist_create(value);
	if (!element)
		return ;
	prev_element = NULL;
	current_element = *list;
	if (!current_element
		|| comparator(current_element->value, element->value) > 0)
	{
		element->next = current_element;
		*list = element;
		return ;
	}
	while (current_element
		&& comparator(current_element->value, element->value) <= 0)
	{
		prev_element = current_element;
		current_element = current_element->next;
	}
	ft_llist_insert_after(prev_element, element);
}
