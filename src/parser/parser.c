#include <stdlib.h>

#include "libft/io/reader.h"
#include "libft/string.h"
#include "libft/types.h"

#include "heightmap.h"

static int	add_points(t_heightmap *map, char **words)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (words[i])
	{
		if (!heightmap_add_point(map, ft_atoi(words[i])))
		{
			result = 0;
			break ;
		}
		i++;
	}
	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (result);
}

int	parse_fdf(int fd, t_heightmap *map)
{
	t_reader	reader;
	char		*line;
	char		**words;
	int			error;

	error = 0;
	reader = ft_reader_create(fd, READER_DEFAULT_BUFSIZE);
	line = ft_read_line(&reader);
	while (reader.status == READER_LINE)
	{
		words = ft_split(line, ' ');
		if (!heightmap_add_line(map) || !words || !add_points(map, words))
		{
			error = 1;
			break ;
		}
		free(line);
		line = ft_read_line(&reader);
	}
	free(line);
	ft_reader_free(&reader);
	if (error || reader.status == READER_ERROR)
		heightmap_free(map);
	return (!error && reader.status != READER_ERROR);
}
