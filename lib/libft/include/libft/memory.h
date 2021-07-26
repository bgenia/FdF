#ifndef MEMORY_H
# define MEMORY_H

# include <unistd.h>

void
ft_bzero(void *s, size_t n);

void
*ft_calloc(size_t count, size_t size);

void
*ft_realloc(void *ptr, size_t old_size, size_t new_size);

void
*ft_reallocarray(void *ptr, size_t old_n, size_t new_n, size_t size);

void
*ft_free(void *ptr);

void
ft_free_each(void **arr, size_t size);

void
*ft_free_array(void **arr, size_t size);

int
ft_nullguard(void *ptr, void **var);

#endif
