#include <stdlib.h>
#include <unistd.h>

#include "libft/string.h"
#include "libft/memory.h"

static int	ft_contains(char const *set, char c)
{
	size_t	i;

	if (!set)
		return (0);
	i = 0;
	while (i < ft_strlen(set))
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	s1_length;
	char	*result_start;
	char	*result_end;
	char	*result;
	size_t	i;

	if (!str)
		return (ft_calloc(1, sizeof(char)));
	s1_length = ft_strlen(str);
	i = 0;
	while (ft_contains(set, str[i]) && i < s1_length)
		i++;
	if (i == s1_length)
		return (ft_calloc(1, sizeof(char)));
	result_start = (char *)&str[i];
	i = s1_length - 1;
	while (ft_contains(set, str[i]) && i > 0)
		i--;
	result_end = (char *)&str[i + 1];
	result = malloc(sizeof(*result) * (result_end - result_start + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, result_start, result_end - result_start);
	result[result_end - result_start] = '\0';
	return (result);
}
