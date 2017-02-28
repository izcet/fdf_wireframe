/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:59:49 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 21:29:35 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define G (*grid)

static t_color	*get_color_from_spectrum(t_grid *grid, int row, int col)
{
	int				range;
	int				val;
	int				i;
	int				off;
	unsigned int	ret;

	if (G.num_cols == 1)
		return (set_color_from_int(set_color(G.cols[0])));
	if (G.p[row][col].z == G.z_max)
		return (set_color_from_int(set_color(G.cols[G.num_cols - 1])));
	range = G.z_max - G.z_min;
	off = range / (G.num_cols - 1);
	val = G.p[row][col].z - G.z_min;
	i = 1;
	while (i < G.num_cols && (val > (i * off)))
		i++;
	ret = gradient_color(G.cols[i - 1], G.cols[i], val - (i * off), off);
	return (set_color_from_int(ret));
}

void			set_point_colors(t_grid *grid)
{
	int		row;
	int		col;

	row = 0;
	while (row < G.length)
	{
		col = 0;
		while (col < G.width)
		{
			if (!G.p[row][col].color)
				G.p[row][col].color = get_color_from_spectrum(grid, row, col);
			col++;
		}
		row++;
	}
}
