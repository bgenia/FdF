#include "mlx.h"

#include "render.h"

t_image_data	create_frame(t_renderer *renderer)
{
	t_image_data	frame;

	frame.image = mlx_new_image(
			renderer->mlx,
			renderer->width,
			renderer->height
			);
	frame.address = mlx_get_data_addr(
			frame.image,
			&frame.bits_per_pixel,
			&frame.line_length,
			&frame.endian
			);
	return (frame);
}
