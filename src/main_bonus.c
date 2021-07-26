#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "mlx.h"

#include "libft/io/printf.h"

#include "heightmap.h"
#include "parser.h"
#include "render.h"
#include "scene.h"
#include "fdf.h"

#ifdef BONUS

static void	print_controls(void)
{
	ft_printf("Scene contols:\n");
	ft_printf("[W][A][S][D] - Move across the scene\n");
	ft_printf("[Q][E] - Rotate the scene to the left/right\n");
	ft_printf("[R][F] - Zoom in and out of the scene\n");
	ft_printf("[Esc] - Exit\n");
	ft_printf("Projection controls:\n");
	ft_printf("[1] - Reset to isometric projection\n");
	ft_printf("[2] - Decrease XY angle\n");
	ft_printf("[3] - Increase XY angle\n");
	ft_printf("[4] - Reset to zero for manual adjustment (line projection)\n");
	ft_printf("[Insert][Delete] - Increase/Decrease X angle\n");
	ft_printf("[Home][End] - Increase/Decrease Y angle\n");
	ft_printf("[PgUp][PgDown] - Increase/Decrease Z angle\n");
}

static void	controls_hook(int key_code, t_scene *scene)
{
	close_esc_hook(key_code, scene);
	scene_controls_hook(key_code, scene);
	projection_controls_hook(key_code, scene);
	angle_controls_hook(key_code, scene);
	render_scene(*scene);
	render_next_frame(&scene->renderer);
}

void	_main(t_heightmap map)
{
	t_renderer	renderer;
	t_view		view;
	t_scene		scene;

	view = view_create(map, projection_isometric());
	renderer = renderer_create(W_WIDTH, W_HEIGHT, "bgenia/FdF");
	scene = scene_create(map, view, renderer);
	render_scene(scene);
	render_next_frame(&scene.renderer);
	mlx_key_hook(scene.renderer.window, (void *)controls_hook, &scene);
	print_controls();
	mlx_loop(scene.renderer.mlx);
	renderer_destroy(&renderer);
}

int	main(int argv, char **argc)
{
	int			fd;
	t_heightmap	map;

	if (argv != 2)
		return (0);
	fd = open(argc[1], O_RDONLY);
	if (fd == -1)
		return (0);
	map = heightmap_create();
	if (!parse_fdf(fd, &map))
	{
		close(fd);
		return (0);
	}
	_main(map);
	heightmap_free(&map);
	close(fd);
	return (0);
}

#endif
