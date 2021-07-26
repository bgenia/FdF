#include "libft/llist.h"

void	ft_llist_sorted_merge(
	t_llist **list1,
	t_llist *list2,
	int (*comparator)()
)
{
	t_llist	*current_element;
	t_llist	*temp_element;

	current_element = list2;
	while (current_element)
	{
		temp_element = current_element->next;
		ft_llist_sorted_insert(list1, current_element, comparator);
		current_element = temp_element;
	}
}
