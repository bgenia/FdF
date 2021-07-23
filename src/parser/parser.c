#include <stdlib.h>

#include "libft/io/get_next_line.h"
#include "libft/string.h"
#include "libft/types.h"
#include "libft/utils.h"

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
	char	*state;
	char	*line;
	char	**words;
	int		gnl_status;

	state = NULL;
	gnl_status = ft_get_next_line(fd, &line, &state, 32);
	while (gnl_status == GNL_LINE)
	{
		heightmap_add_line(map);
		words = ft_split(line, ' ');
		if (!words)
			return (ft_free2pass(line, state, 0));
		if (!add_points(map, words))
			break ;
		free(line);
		gnl_status = ft_get_next_line(fd, &line, &state, 32);
	}
	free(line);
	free(state);
	return (gnl_status == GNL_EOF);
}
