#include "mgl.h"

#define D (*data)
#define W (*(D.win[i]))

void	set_window_hooks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < D.num_win)
	{
		mlx_key_hook(W.ptr, key_pressed, D.win[i]);
		mlx_mouse_hook(W.ptr, mouse_pressed, D.win[i]);
		mlx_expose_hook(W.ptr, expose_hook, D.win[i]);
		mlx_loop_hook(D.mlx, loop_hook, D.win[i]);
	}
}
