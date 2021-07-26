#include "libft/llist.h"

void	ft_llist_for_each_if(
	t_llist *list,
	void (*f)(void *),
	void *value,
	int (*comparator)()
)
{
	t_llist	*current_element;

	current_element = list;
	while (current_element)
	{
		if (comparator(current_element->value, value) == 0)
			f(current_element->value);
		current_element = current_element->next;
	}
}
