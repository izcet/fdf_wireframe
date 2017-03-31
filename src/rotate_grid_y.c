#include "mgl.h"

#define D (*data)

void	rotate_grid_y_pos(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < D.len)
	{
		col = 0;
		while (col < D.wid)
		{
			rot_poy(D.map3d[row][col], ROT_ANGLE);
			col++;
		}
		row++;
	}
}

void	rotate_grid_y_neg(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < D.len)
	{
		col = 0;
		while (col < D.wid)
		{
			rot_poy(D.map3d[row][col], (ROT_ANGLE * -1));
			col++;
		}
		row++;
	}
}
