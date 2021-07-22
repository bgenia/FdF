#include "color.h"

#include <stdio.h>

t_color	get_height_color(int height)
{
	if (height < -10)
		height = -10;
	if (height > 9)
		height = 9;
	height += 10;
	printf("HEIGHT COLOR> %d\n", height);
	return (gradient_get_color(0xFFFFFF, 0xFF0000, 20, height));
}
