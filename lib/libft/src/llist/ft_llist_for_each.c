#include "libft/llist.h"

void	ft_llist_for_each(t_llist *list, void (*f)(void*))
{
	t_llist	*element;

	element = list;
	while (element)
	{
		f(element->value);
		element = element->next;
	}
}
