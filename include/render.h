#ifndef RENDER_H
# define RENDER_H

# include "mlx.h"
# include "tuples.h"
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

//FIXME: Implement
t_brush
brush_solid(t_color color);

//FIXME: Implement
t_brush
brush_gradient(t_color from, t_color to);

t_image_data
create_frame(t_renderer *renderer);

t_renderer
renderer_init(void *mlx, void *window, int width, int height);
void
render_next_frame(t_renderer *renderer);

void
draw_pixel(t_renderer *renderer, t_color color, t_int2 position);

typedef struct s_line
{
	t_int2	a;
	t_int2	b;
}
t_line;

void
draw_line(t_renderer *renderer, t_brush brush, t_line line);

#endif
