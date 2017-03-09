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

#define G (*grid)

static t_xy		*get_window_point(int row, int col, t_zc p, t_data *data)
{
	t_xy	*point;

	point = (t_xy*)malloc(sizeof(t_xy));
	if (!point)
		return (NULL);
	ft_bzero(point, sizeof(t_xy));
	(*point).x = (col + 1) * (*(*data).win).scale;
	(*point).y = (row + 1) * (*(*data).win).scale;
	(*point).color = p.color;
	return (point);
}

void			draw_grid(t_grid *grid, t_data *data, int row, int col)
{
	t_xy	*p1;
	t_xy	*p2;

	while (++row < G.length)
	{
		col = -1;
		while (++col < G.width)
		{
			p1 = get_window_point(row, col, G.p[row][col], data);
			if (row < G.length - 1)
			{
				p2 = get_window_point(row + 1, col, G.p[row + 1][col], data);
				draw_line(p1, p2, data);
				free(p2);
			}
			if (col < G.width - 1)
			{
				p2 = get_window_point(row, col + 1, G.p[row][col + 1], data);
				draw_line(p1, p2, data);
				free(p2);
			}
			free(p1);
		}
	}
}
