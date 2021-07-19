#include "mlx.h"

#include "render.h"

#define W_WIDTH		640
#define W_HEIGHT	480

int	main(void)
{
	void		*mlx;
	void		*window;
	t_renderer	renderer;

	mlx = mlx_init();
	window = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "FdF <Tech Demo>");
	renderer = renderer_init(mlx, window, W_WIDTH, W_HEIGHT);
	draw_line(
		&renderer,
		(t_brush){.color = 0xFF0000},
		(t_spoint){.x = 0, .y = 0},
		(t_spoint){.x = W_WIDTH, .y = W_HEIGHT}
		);
	render_next_frame(&renderer);
	mlx_loop(mlx);
	return (0);
}
