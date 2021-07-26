#include "libft/llist.h"

t_llist	*ft_llist_from(int count, void **values, void (*_free)(void *))
{
	int		i;
	t_llist	*list;
	t_llist	*current_element;

	i = 0;
	list = NULL;
	while (i < count)
	{
		current_element = ft_llist_create(values[i]);
		if (!current_element)
		{
			ft_llist_clear(&list, _free);
			return (list);
		}
		ft_llist_add_back(&list, current_element);
		i++;
	}
	return (list);
}
