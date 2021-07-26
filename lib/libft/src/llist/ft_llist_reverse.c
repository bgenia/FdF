#include "libft/llist.h"

void	ft_llist_reverse(t_llist **list)
{
	t_llist	*prev_element;
	t_llist	*current_element;
	t_llist	*temp_element;

	prev_element = NULL;
	current_element = *list;
	while (current_element)
	{
		temp_element = current_element->next;
		if (prev_element)
			current_element->next = prev_element;
		else
			current_element->next = NULL;
		prev_element = current_element;
		current_element = temp_element;
	}
	*list = prev_element;
}
