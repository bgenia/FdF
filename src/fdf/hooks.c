#include <stdlib.h>
#include <math.h>

#include "scene.h"

void	close_esc_hook(int key_code, t_scene *scene)
{
	if (key_code != 0xFF1B)
		return ;
	renderer_destroy(&scene->renderer);
	heightmap_free(&scene->map);
	exit(EXIT_SUCCESS);
}

void	scene_controls_hook(int key_code, t_scene *scene)
{
	if (key_code == 0x61)
		scene->view.render_offset.x--;
	if (key_code == 0x64)
		scene->view.render_offset.x++;
	if (key_code == 0x77)
		scene->view.render_offset.y--;
	if (key_code == 0x73)
		scene->view.render_offset.y++;
	if (key_code == 0x71)
		scene->view.angle += M_PI / 12;
	if (key_code == 0x65)
		scene->view.angle -= M_PI / 12;
	if (key_code == 0x72)
		scene->view.zoom += 2;
	if (key_code == 0x66)
		scene->view.zoom -= 2;
	if (scene->view.angle > M_PI)
		scene->view.angle -= M_PI * 2;
	if (scene->view.angle < -M_PI)
		scene->view.angle += M_PI * 2;
}

void	projection_controls_hook(int key_code, t_scene *scene)
{
	if (key_code == 0x31)
		scene->view.projection = projection_isometric();
	if (key_code == 0x34)
		scene->view.projection = projection_line();
	if (key_code == 0x32)
	{
		scene->view.projection.angle.x -= M_PI / 12;
		scene->view.projection.angle.y += M_PI / 12;
	}
	if (key_code == 0x33)
	{
		scene->view.projection.angle.x += M_PI / 12;
		scene->view.projection.angle.y -= M_PI / 12;
	}
}

void	angle_controls_hook(int key_code, t_scene *scene)
{
	if (key_code == 0xFF63)
		scene->view.projection.angle.x += M_PI / 12;
	if (key_code == 0xFFFF)
		scene->view.projection.angle.x -= M_PI / 12;
	if (key_code == 0xFF50)
		scene->view.projection.angle.y += M_PI / 12;
	if (key_code == 0xFF57)
		scene->view.projection.angle.y -= M_PI / 12;
	if (key_code == 0xFF55)
		scene->view.projection.angle.z += M_PI / 12;
	if (key_code == 0xFF56)
		scene->view.projection.angle.z -= M_PI / 12;
}
