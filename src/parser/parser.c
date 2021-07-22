#include <stdlib.h>

#include "libft/io/get_next_line.h"
#include "libft/string.h"
#include "libft/types.h"
#include "libft/utils.h"

#include "space.h"

static int	add_points(t_space3d *space, char **words)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (words[i])
	{
		if (!space3d_add_point(space, ft_atoi(words[i])))
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

int	parse_fdf(int fd, t_space3d *space)
{
	char	*state;
	char	*line;
	char	**words;
	int		gnl_status;

	state = NULL;
	gnl_status = ft_get_next_line(fd, &line, &state, 32);
	while (gnl_status == GNL_LINE)
	{
		space3d_add_line(space);
		words = ft_split(line, ' ');
		if (!words)
			return (ft_free2pass(line, state, 0));
		if (!add_points(space, words))
			break ;
		free(line);
		gnl_status = ft_get_next_line(fd, &line, &state, 32);
	}
	free(line);
	free(state);
	return (gnl_status == GNL_EOF);
}
