#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "mlx.h"

#include "heightmap.h"
#include "render.h"
#include "scene.h"
#include "fdf.h"

static void	close_esc_hook(int key_code, t_scene *scene)
{
	if (key_code != 65307)
		return ;
	renderer_destroy(&scene->renderer);
	heightmap_free(&scene->map);
	exit(EXIT_SUCCESS);
}

int	main(int argv, char **argc)
{
	int			fd;
	t_heightmap	map;
	t_renderer	renderer;
	t_view		view;
	t_scene		scene;

	if (argv != 2)
		return (0);
	fd = open(argc[1], O_RDONLY);
	if (fd == -1)
		return ;
	map = heightmap_create();
	parse_fdf(fd, &map);
	view = view_create(map, projection_isometric());
	renderer = renderer_create(W_WIDTH, W_HEIGHT, "bgenia/FdF");
	scene = scene_create(map, view, renderer);
	heightmap_edges_foreach(&map, render_edge, &scene);
	render_next_frame(&scene.renderer);
	mlx_key_hook(scene.renderer.window, close_esc_hook, &scene);
	mlx_loop(scene.renderer.mlx);
	renderer_destroy(&renderer);
	heightmap_free(&scene.map);
	close(fd);
}
