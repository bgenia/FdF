#include "mlx.h"

#include "render.h"

t_renderer	renderer_init(void *mlx, void *window, int width, int height)
{
	t_renderer	renderer;

	renderer.mlx = mlx;
	renderer.window = window;
	renderer.width = width;
	renderer.height = height;
	renderer.next_frame = create_frame(&renderer);
	return (renderer);
}
