#include "libft/llist.h"

t_llist	*ft_llist_at(t_llist *list, unsigned int index)
{
	unsigned int	i;
	t_llist			*current_element;

	i = 0;
	current_element = list;
	while (current_element && i < index)
	{
		i++;
		current_element = current_element->next;
	}
	if (i != index)
		return (NULL);
	return (current_element);
}
