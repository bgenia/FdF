#include <stdlib.h>

#include "libft/llist.h"

t_llist	*ft_llist_create(void *value)
{
	t_llist	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->value = value;
	list->next = NULL;
	return (list);
}
