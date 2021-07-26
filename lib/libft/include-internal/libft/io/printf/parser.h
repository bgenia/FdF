#ifndef PARSER_H
# define PARSER_H

# include "placeholder.h"

unsigned int	parse_uint(const char **str);

void			parse_flags(const char **str, t_placeholder *pl);
void			parse_width(const char **str, t_placeholder *pl);
void			parse_precision(const char **str, t_placeholder *pl);
void			parse_size(const char **str, t_placeholder *pl);
void			parse_type(const char **str, t_placeholder *pl);

t_placeholder	*parse_placeholder(const char **format);

#endif
