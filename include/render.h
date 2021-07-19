#ifndef RENDER_H
# define RENDER_H

# include "mlx.h"

typedef struct s_image_data
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image_data;

typedef struct s_renderer
{
	void			*mlx;
	void			*window;
	int				width;
	int				height;
	t_image_data	current_frame;
	t_image_data	next_frame;
}	t_renderer;

typedef struct s_brush
{
	int	color;
}	t_brush;

typedef struct s_spoint
{
	int	x;
	int	y;
}	t_spoint;

t_image_data	create_frame(t_renderer *renderer);

t_renderer		renderer_init(void *mlx, void *window, int width, int height);
void			render_next_frame(t_renderer *renderer);

void			draw_pixel(
					t_renderer *renderer, t_brush brush, t_spoint position
					);
void			draw_line(
					t_renderer *renderer, t_brush brush, t_spoint a, t_spoint b
					);

#endif
