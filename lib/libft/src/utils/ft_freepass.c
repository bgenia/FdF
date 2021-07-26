#include <stdlib.h>

int	ft_free1pass(void *ptr, int pass)
{
	free(ptr);
	return (pass);
}

int	ft_free2pass(void *ptr1, void *ptr2, int pass)
{
	free(ptr1);
	free(ptr2);
	return (pass);
}
