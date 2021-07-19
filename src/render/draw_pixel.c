#include "mlx.h"

#include "render.h"

static unsigned long	get_pixel_memory_offset(
	t_image_data frame,
	t_spoint position
)
{
	int	offsetY;
	int	offsetX;

	offsetY = position.y * frame.line_length;
	offsetX = position.x * (frame.bits_per_pixel / 8);
	return (offsetY + offsetX);
}

void	draw_pixel(t_renderer *renderer, t_brush brush, t_spoint position)
{
	unsigned int	*pixel_address;

	pixel_address = renderer->next_frame.address;
	pixel_address += get_pixel_memory_offset(renderer->next_frame, position);
	*pixel_address = brush.color;
}
