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

#ifndef BONUS

static void	print_controls(void)
{
	ft_printf("App contols:\n");
	ft_printf("[Esc] - Exit\n");
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
	mlx_key_hook(scene.renderer.window, (void *)close_esc_hook, &scene);
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
