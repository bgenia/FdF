#include "mlx.h"

#include "render.h"

static void	render_current_frame(t_renderer *renderer)
{
	mlx_put_image_to_window(
		renderer->mlx,
		renderer->window,
		renderer->current_frame.image,
		0,
		0
		);
}

void	render_next_frame(t_renderer *renderer)
{
	t_image_data	prev_frame;

	prev_frame = renderer->current_frame;
	renderer->current_frame = renderer->next_frame;
	render_current_frame(renderer);
	renderer->next_frame = create_frame(renderer);
	if (prev_frame.image)
		mlx_destroy_image(renderer->mlx, prev_frame.image);
}
