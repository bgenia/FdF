#include "scene.h"
#include "heightmap.h"
#include "render.h"

t_scene	scene_create(t_heightmap map, t_view view, t_renderer renderer)
{
	t_scene	scene;

	scene.map = map;
	scene.renderer = renderer;
	scene.view = view;
	return (scene);
}
