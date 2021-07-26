#include "mlx.h"

#include "libft/tuples.h"
#include "libft/math.h"

#include "render.h"

static t_int2	get_window_size(void *mlx, int max_x, int max_y)
{
	t_int2	size;

	mlx_get_screen_size(mlx, &size.x, &size.y);
	size.x = ft_min(max_x, size.x);
	size.y = ft_min(max_y, size.y);
	return (size);
}

t_renderer	renderer_create(int width, int height, char *title)
{
	void		*mlx;
	void		*window;
	t_int2		screen_size;
	t_renderer	renderer;

	mlx = mlx_init();
	screen_size = get_window_size(mlx, width, height);
	window = mlx_new_window(mlx, screen_size.x, screen_size.y, title);
	renderer.mlx = mlx;
	renderer.window = window;
	renderer.width = width;
	renderer.height = height;
	renderer.next_frame = create_frame(&renderer);
	renderer.current_frame = (t_image_data){0};
	return (renderer);
}
