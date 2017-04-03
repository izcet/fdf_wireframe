#include "mgl.h"

#define W (*win)
#define D (*W.data)

int		loop_hook(void *param)
{
	t_win	*win;

	win = (t_win*)param;
	mlx_clear_window(D.mlx, W.ptr);
	draw_grid(win);
	return (0);
}
