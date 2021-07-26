#include "libft/llist.h"

void	ft_llist_swap_values(
	t_llist *list,
	unsigned int index1,
	unsigned int index2
)
{
	t_llist	*element1;
	t_llist	*element2;
	void	*temp_value;

	element1 = ft_llist_at(list, index1);
	element2 = ft_llist_at(list, index2);
	temp_value = element1->value;
	element1->value = element2->value;
	element2->value = temp_value;
}
