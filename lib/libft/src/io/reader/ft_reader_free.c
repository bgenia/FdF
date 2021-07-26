#include <stdlib.h>

#include "libft/io/reader.h"

void	ft_reader_free(t_reader *reader)
{
	free(reader->remainder);
	reader->remainder = NULL;
}
