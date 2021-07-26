#include "libft/llist.h"

void	ft_llist_reverse_values(t_llist *list)
{
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_llist_size(list);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			ft_llist_swap_values(list, i, j);
			j++;
		}
		i++;
	}
}
