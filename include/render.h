#ifndef RENDER_H
# define RENDER_H

# include "mlx.h"
# include "libft/tuples.h"
# include "color.h"

typedef struct s_image_data
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}
t_image_data;

typedef struct s_renderer
{
	void			*mlx;
	void			*window;
	int				width;
	int				height;
	t_image_data	current_frame;
	t_image_data	next_frame;
}
t_renderer;

typedef struct s_brush
{
	t_color			color;
	t_color			color2;
}
t_brush;

t_brush
brush_solid(t_color color);

t_brush
brush_gradient(t_color from, t_color to);

t_image_data
create_frame(t_renderer *renderer);

t_renderer
renderer_create(int width, int height, char *title);
void
renderer_destroy(t_renderer *renderer);

void
render_next_frame(t_renderer *renderer);

void
draw_pixel(t_renderer *renderer, t_color color, t_int2 position);

void
draw_line(t_renderer *renderer, t_brush brush, t_int2 from, t_int2 to);

#endif
