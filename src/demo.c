#include "mlx.h"

#include "libft/io/printf.h"
#include "libft/utils.h"

#include "render.h"
#include "matrix.h"
#include "heightmap.h"
#include "parser.h"
#include "tuples.h"
#include "projection.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#include <stdio.h>

#define W_WIDTH		1200
#define W_HEIGHT	680

double			g_angle = 0;
double			g_zoom = 1;
double			g_x_translate = 0;
double			g_y_translate = 0;
int				g_render_direction = 1;
t_projection	g_projection;

static t_int2	project_point(t_heightmap *map, t_int3 point, double xy_scale, double angle)
{
	t_dmatrix	vector;
	t_dmatrix	projection;
	t_dmatrix	rotation;
	t_dmatrix	result1;
	t_dmatrix	result2;
	t_int2		spoint;

	vector = m_vector(
		(double)point.x - (double)map->width / 2,
		(double)point.y - (double)map->height / 2,
		(double)point.z - (map->max_elevation - map->min_elevation) / 2
		);
	projection = projection_matrix(g_projection);
	rotation = m_rotation(angle);
	result1 = dmatrix_create(3, 3, (double []){0, 0, 0});
	dmatrix_multiply(rotation, vector, &result1);
	result2 = dmatrix_create(2, 1, (double []){0, 0});
	dmatrix_multiply(projection, result1, &result2);
	result2.value[0] += g_x_translate;
	result2.value[1] += g_y_translate;
	spoint.x = (int)round(dmatrix_get(result2, 0, 0) * xy_scale);
	spoint.y = (int)round(dmatrix_get(result2, 1, 0) * xy_scale);
	return (spoint);
}

static double	compute_scale(t_heightmap *map)
{
	int		width;
	int		length;
	int		height;
	double	size;
	double	scale;

	width = map->width;
	length = map->height;
	height = map->max_elevation - map->min_elevation;
	size = ft_max(width, ft_max(length, height));
	scale = -size / 2 + 40;
	if (scale < 3)
		scale = 3;
	if (scale > 30)
		scale = 30;
	return (scale);
}

static void	draw_edge(t_heightmap *map, t_int3 a, t_int3 b, void *renderer)
{
	t_int2			projectionA;
	t_int2			projectionB;
	int				offset_x;
	int				offset_y;
	int				scale;

	offset_x = W_WIDTH / 2;
	offset_y = W_HEIGHT / 2;
	scale = compute_scale(map);
	projectionA = project_point(map, a, scale + g_zoom, g_angle);
	projectionB = project_point(map, b, scale + g_zoom, g_angle);
	// printf(
	// 	"Edge:\n\tPosition: %d %d %d -> %d %d %d\n\tProjection: %d %d -> %d %d\n",
	// 	a.x, a.y, a.z,
	// 	b.x, b.y, b.z,
	// 	projectionA.x, projectionA.y,
	// 	projectionB.x, projectionB.y
	// 	);
	draw_line(
		renderer,
		brush_gradient(
			// linear_gradient(
			// 	(t_color []){0x0000FF, 0xFFFFFF, 0xFF0000},
			// 	(int []){abs(map->min_elevation), abs(map->max_elevation)},
			// 	a.z + abs(map->min_elevation)
			// 	),
			// linear_gradient(
			// 	(t_color []){0x0000FF, 0xFFFFFF, 0xFF0000},
			// 	(int []){abs(map->min_elevation), abs(map->max_elevation)},
			// 	b.z + abs(map->min_elevation)
			// 	)
			gradient_get_color(
				0x0000FF,
				0xFF0000,
				abs(map->max_elevation - map->min_elevation),
				a.z + abs(map->min_elevation)
				),
			gradient_get_color(
				0x0000FF,
				0xFF0000,
				abs(map->max_elevation - map->min_elevation),
				b.z + abs(map->min_elevation)
				)
			),
		(t_line){
		.a = int2(offset_x + projectionA.x, offset_y + projectionA.y),
		.b = int2(offset_x + projectionB.x, offset_y + projectionB.y)
	});
}

void	print_fdf(t_heightmap *map, t_int3 point)
{
	static int	prev_y = 0;

	if (point.y > prev_y)
		ft_printf("\n");
	ft_printf("%d\t", point.z);
	prev_y = point.y;
}

typedef struct s_context
{
	t_renderer	*renderer;
	t_heightmap	*map;
}
t_context;

void	rotate_handler(int key_code, t_context *context)
{
	if (key_code == 101)
		g_angle -= M_PI / 16;
	else if (key_code == 113)
		g_angle += M_PI / 16;
	else if (key_code == 114)
		g_zoom ++;
	else if (key_code == 102)
		g_zoom --;
	else if (key_code == 119)
		g_y_translate--;
	else if (key_code == 115)
		g_y_translate++;
	else if (key_code == 100)
		g_x_translate++;
	else if (key_code == 97)
		g_x_translate--;
	else if (key_code == 49)
		g_render_direction = 1;
	else if (key_code == 50)
		g_render_direction = 0;
	else if (key_code == 51)
	{
		g_projection.angle.x += M_PI / 12;
		g_projection.angle.y -= M_PI / 12;
	}
	else if (key_code == 52)
	{
		g_projection.angle.x -= M_PI / 12;
		g_projection.angle.y += M_PI / 12;
	}
	else if (key_code == 65307)
		exit(0);
	else
	{
		printf("Key press: %d\n", key_code);
		return ;
	}
	if (g_angle > M_PI)
		g_angle -= M_PI * 2;
	if (g_angle < -M_PI)
		g_angle += M_PI * 2;
	printf("> Angle: %f / %f\n", g_angle, g_angle / M_PI);
	printf("> Render: %d\n", g_render_direction);
	if (g_render_direction == 1)
		heightmap_edges_foreach(context->map, draw_edge, context->renderer);
	else
		heightmap_edges_rforeach(context->map, draw_edge, context->renderer);
	render_next_frame(context->renderer);
}

int	main(void)
{
	t_heightmap	map;
	int			fd;
	void		*mlx;
	void		*window;
	t_renderer	renderer;

	g_projection.angle.x = M_PI / 6;
	g_projection.angle.y = M_PI / 6 * 5;
	g_projection.angle.z = M_PI / -2;
	g_projection.scale.x = 1;
	g_projection.scale.y = 1;
	g_projection.scale.z = 1;
	map = heightmap_init();
	fd = open("kek.fdf", O_RDONLY);
	if (fd)
	{
		ft_printf("Parsing map file . . . \n");
		parse_fdf(fd, &map);
		close(fd);
	}
	mlx = mlx_init();
	window = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "FdF <Tech Demo>");
	renderer = renderer_init(mlx, window, W_WIDTH, W_HEIGHT);
	// mlx_do_key_autorepeaton(mlx);
	ft_printf("Rendering map:\n");
	heightmap_edges_foreach(&map, draw_edge, &renderer);
	// heightmap_points_foreach(&map, print_fdf);
	render_next_frame(&renderer);
	t_context context = (t_context){ .renderer = &renderer, .map = &map };
	mlx_key_hook(window, rotate_handler, &context);
	mlx_loop(mlx);
	heightmap_free(&map);
}
