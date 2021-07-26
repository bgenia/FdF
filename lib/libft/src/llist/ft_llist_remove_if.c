#include <stdlib.h>

#include "libft/llist.h"

void	ft_llist_remove_if(
	t_llist **list,
	void *value,
	int (*comparator)(),
	void (*_free)(void *)
)
{
	t_llist	*prev_element;
	t_llist	*current_element;
	t_llist	*temp_element;

	prev_element = NULL;
	current_element = *list;
	while (current_element)
	{
		if (comparator(current_element->value, value) == 0)
		{
			_free(current_element->value);
			temp_element = current_element->next;
			if (prev_element)
				prev_element->next = current_element->next;
			else
				*list = current_element->next;
			free(current_element);
			current_element = temp_element;
		}
		else
		{
			prev_element = current_element;
			current_element = current_element->next;
		}
	}
}
