#ifndef LLIST_H
# define LLIST_H

# include <unistd.h>

typedef struct s_llist
{
	void			*value;
	struct s_llist	*next;
}
t_llist;

t_llist
*ft_llist_create(void *value);

void
ft_llist_add_front(t_llist **list, t_llist *element);

size_t
ft_llist_size(t_llist *list);

t_llist
*ft_llist_last(t_llist *list);

void
ft_llist_add_back(t_llist **list, t_llist *element);

void
ft_llist_free(t_llist *list, void (*_free)(void*));

void
ft_llist_clear(t_llist **list, void (*_free)(void*));

void
ft_llist_for_each(t_llist *list, void (*f)(void*));

t_llist
*ft_llist_map(t_llist *list, void *(*f)(void *), void (*_free)(void *));

t_llist
*ft_llist_at(t_llist *list, unsigned int index);

t_llist
*ft_llist_find(t_llist *list, void *value, int (*comparator)());

void
ft_llist_for_each_if(
	t_llist *list,
	void (*f)(void *),
	void *value,
	int (*comparator)()
	);

t_llist
*ft_llist_from(int count, void **values, void (*_free)(void *));

void
ft_llist_insert_after(t_llist *list, t_llist *element);

void
ft_llist_merge(t_llist **list1, t_llist *list2);

void
ft_llist_remove_if(
	t_llist **list,
	void *value,
	int (*comparator)(),
	void (*_free)(void *)
	);

void
ft_llist_reverse_values(t_llist *list);

void
ft_llist_reverse(t_llist **list);

void
ft_llist_sort(t_llist **list, int (*comparator)());

void
ft_llist_swap_elements(
	t_llist **list,
	unsigned int index1,
	unsigned int index2
	);

void
ft_llist_swap_values(t_llist *list, unsigned int index1, unsigned int index2);

void
ft_llist_sorted_insert(t_llist **list, void *value, int (*comparator)());

void
ft_llist_sorted_merge(t_llist **list1, t_llist *list2, int (*comparator)());

#endif
