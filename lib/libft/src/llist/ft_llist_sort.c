#include "libft/llist.h"

void	ft_llist_sort(t_llist **list, int (*comparator)())
{
	size_t	i;
	size_t	j;
	void	*a;
	void	*b;
	size_t	size;

	i = 0;
	size = ft_llist_size(*list);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			a = ft_llist_at(*list, j)->value;
			b = ft_llist_at(*list, j + 1)->value;
			if (comparator(a, b) > 0)
				ft_llist_swap_elements(list, j, j + 1);
			j++;
		}
		i++;
	}
}
