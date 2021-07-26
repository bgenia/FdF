#include "libft/llist.h"

t_llist	*ft_llist_map(t_llist *list, void *(*f)(void *), void (*_free)(void *))
{
	t_llist	*result;
	t_llist	*result_current;
	t_llist	*lst_current;

	result = NULL;
	lst_current = list;
	while (lst_current)
	{
		result_current = ft_llist_create(f(lst_current->value));
		if (!result_current)
		{
			ft_llist_clear(&result, _free);
			break ;
		}
		ft_llist_add_back(&result, result_current);
		lst_current = lst_current->next;
	}
	return (result);
}
