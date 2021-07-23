#include "libft/io/printf.h"

static void	print_controls(void)
{
	ft_printf("Scene contols:\n");
	ft_printf("[W][A][S][D] - Move across the scene\n");
	ft_printf("[Q][E] - Rotate the scene to the left/right\n");
	ft_printf("[R][F] - Zoom in and out of the scene\n");
	ft_printf("Projection controls:\n");
	ft_printf("[1] - Reset to isometric projection\n");
	ft_printf("[2] - Decrease XY angle\n");
	ft_printf("[3] - Increase XY angle\n");
	ft_printf("[4] - Reset to zero for manual adjustment (line projection)\n");
	ft_printf("[Insert][Delete] - Increase/Decrease X angle\n");
	ft_printf("[Home][End] - Increase/Decrease Y angle\n");
	ft_printf("[PgUp][PgDown] - Increase/Decrease Z angle\n");
}
-
