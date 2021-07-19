#include "mlx.h"

#include "libft/io/printf.h"

#include "render.h"
#include "matrix.h"
#include "space.h"

#define W_WIDTH		640
#define W_HEIGHT	480

// int	main(void)
// {
// 	void		*mlx;
// 	void		*window;
// 	t_renderer	renderer;

// 	mlx = mlx_init();
// 	window = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "FdF <Tech Demo>");
// 	renderer = renderer_init(mlx, window, W_WIDTH, W_HEIGHT);
// 	draw_line(
// 		&renderer,
// 		(t_brush){.color = 0xFF0000},
// 		(t_spoint){.x = 0, .y = 0},
// 		(t_spoint){.x = W_WIDTH, .y = W_HEIGHT}
// 		);
// 	render_next_frame(&renderer);
// 	mlx_loop(mlx);
// 	return (0);
// }

void	print_point(t_point3d point)
{
	ft_printf("Point3D: %d %d %d\n", point.x, point.y, point.z);
}

void	print_edge(t_point3d a, t_point3d b)
{
	ft_printf("Edge3D: %d %d %d -> %d %d %d\n", a.x, a.y, a.z, b.x, b.y, b.z);
}

// void	draw_point(t_point3d point, t_renderer *renderer)
// {
// 	draw_pixel(
// 		renderer,
// 		(t_brush){.color = 0xFF0000},
// 		(t_spoint){.x = point.x, .y = point.y}
// 		);
// }

void	draw_edge(t_point3d a, t_point3d b, void *renderer)
{
	ft_printf("Edge3D: %d %d %d -> %d %d %d\n", a.x, a.y, a.z, b.x, b.y, b.z);
	draw_line(
		renderer,
		(t_brush){.color = 0x00FF00},
		(t_spoint){.x = 50 + a.x * 100, .y = 50 + a.y * 100},
		(t_spoint){.x = 50 + b.x * 100, .y = 50 + b.y * 100}
		);
}

int	main(void)
{
	t_space3d	space;
	void		*mlx;
	void		*window;
	t_renderer	renderer;

	space = space3d_init();
	space3d_add_point(&space, 10);
	space3d_add_point(&space, 20);
	space3d_add_point(&space, 30);
	space3d_add_line(&space);
	space3d_add_point(&space, 11);
	space3d_add_point(&space, 12);
	space3d_add_point(&space, 13);
	space3d_add_line(&space);
	space3d_add_point(&space, 14);
	space3d_add_point(&space, 15);
	space3d_add_point(&space, 16);
	// space3d_points_foreach(&space, print_point);
	// space3d_edges_foreach(&space, print_edge);
	mlx = mlx_init();
	window = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "FdF <Tech Demo>");
	renderer = renderer_init(mlx, window, W_WIDTH, W_HEIGHT);
	space3d_edges_foreach(&space, draw_edge, &renderer);
	// draw_line(
	// 	&renderer,
	// 	(t_brush){.color = 0xFF0000},
	// 	(t_spoint){.x = 50, .y = 250},
	// 	(t_spoint){.x = 50, .y = 50}
	// 	);
	// space3d_points_foreach(&space, draw_point, &renderer);
	render_next_frame(&renderer);
	mlx_loop(mlx);
	space3d_free(&space);
}
