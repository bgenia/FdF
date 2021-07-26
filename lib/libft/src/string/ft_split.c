#include <stdlib.h>
#include <unistd.h>

#include "libft/string.h"

static char	*find_next_separator(char *str, char separator)
{
	char	*next_separator;

	next_separator = ft_strchr(str, separator);
	if (!next_separator)
		next_separator = ft_strchr(str, '\0');
	return (next_separator);
}

static char	*find_next_word(char *str, char separator)
{
	while (*str)
	{
		if (find_next_separator(str, separator) - str > 0)
			return (str);
		str++;
	}
	return (NULL);
}

static size_t	get_word_count(char *str, char separator)
{
	size_t	word_count;
	size_t	word_length;

	word_count = 0;
	if (!str)
		return (word_count);
	str = find_next_word(str, separator);
	while (str)
	{
		word_count++;
		word_length = find_next_separator(str, separator) - str;
		str = find_next_word(str + word_length, separator);
	}
	return (word_count);
}

static void	*free_result(char **result, size_t word_count)
{
	size_t	j;

	j = word_count;
	while (j-- > 0)
		free(result[j]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *str, char separator)
{
	char	**result;
	char	*word;
	size_t	i;
	size_t	word_length;

	result = malloc(sizeof(*result)
			* (get_word_count((char *) str, separator) + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (str)
		str = find_next_word((char *) str, separator);
	while (str)
	{
		word_length = find_next_separator((char *) str, separator) - str;
		word = malloc(sizeof(*word) * (word_length + 1));
		if (!word)
			return (free_result(result, i));
		ft_memcpy(word, str, word_length);
		word[word_length] = '\0';
		result[i++] = word;
		str = find_next_word((char *) &str[word_length], separator);
	}
	result[i] = NULL;
	return (result);
}
