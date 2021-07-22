#include "mlx.h"

#include "render.h"

#include <stdio.h>

static unsigned long	get_pixel_memory_offset(
	t_image_data frame,
	t_int2 position
)
{
	int	offsetY;
	int	offsetX;

	offsetY = position.y * frame.line_length;
	offsetX = position.x * (frame.bits_per_pixel / 8);
	return (offsetY + offsetX);
}

void	draw_pixel(t_renderer *renderer, t_color color, t_int2 position)
{
	char	*pixel_address;

	if (position.x < 0 || position.y < 0)
		return ;
	if (position.x > renderer->width || position.y > renderer->height)
		return ;
	pixel_address = renderer->next_frame.address;
	pixel_address += get_pixel_memory_offset(renderer->next_frame, position);
	*(unsigned int *)pixel_address = color;
}
