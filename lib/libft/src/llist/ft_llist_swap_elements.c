#include "libft/llist.h"

void	ft_llist_swap_elements(
	t_llist **list,
	unsigned int index1,
	unsigned int index2
)
{
	t_llist	*first_element;
	t_llist	*second_element;
	t_llist	*temp_element;

	first_element = ft_llist_at(*list, index1);
	second_element = ft_llist_at(*list, index2);
	if (index1 > 0)
	{
		temp_element = ft_llist_at(*list, index1 - 1);
		temp_element->next = second_element;
	}
	else
	{
		*list = second_element;
	}
	temp_element = second_element->next;
	second_element->next = first_element->next;
	first_element->next = temp_element;
	temp_element = ft_llist_at(*list, index2 - 1);
	temp_element->next = first_element;
}
