/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:23:04 by irhett            #+#    #+#             */
/*   Updated: 2017/03/01 01:19:06 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define W (*win)
#define D (*W.data)
#define P (*p)

static t_xyzcp	*get_win_point(unsigned int row, unsigned int col, t_win *win)
{
	t_xyzcp	*p;

	p = init_xyzcp();
	if (!p)
		return (NULL);
	P.x = (W.center_x) + (W.scale * (*D.map3d[row][col]).x);
	P.y = (W.center_y) + (W.scale * (*D.map3d[row][col]).y);
	if (W.true_z)
		P.y -= (W.scale * (*D.map3d[row][col]).z);
	else
		P.y -= (*D.map3d[row][col]).z;
	P.c = (*(D.map[row][col])).c;
	return (p);
}

void			draw_grid(t_win *win)
{
	t_xyzcp			*p1;
	t_xyzcp			*p2;
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < D.len)
	{
		col = 0;
		while (col < D.wid)
		{
			p1 = get_win_point(row, col, win);
			if (row < D.len - 1)
			{
				p2 = get_win_point(row + 1, col, win);
				draw_line(p1, p2, win);
			}
			if (col < D.wid - 1)
			{
				p2 = get_win_point(row, col + 1, win);
				draw_line(p1, p2, win);
			}
			free(p1);
			col++;
		}
		row++;
	}
}
