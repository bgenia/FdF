#include <stdlib.h>

#include "mlx.h"

#include "render.h"

void	renderer_destroy(t_renderer *renderer)
{
	mlx_destroy_window(renderer->mlx, renderer->window);
	mlx_destroy_image(renderer->mlx, renderer->current_frame.image);
	mlx_destroy_image(renderer->mlx, renderer->next_frame.image);
	mlx_destroy_display(renderer->mlx);
	renderer->mlx = NULL;
	renderer->window = NULL;
}
