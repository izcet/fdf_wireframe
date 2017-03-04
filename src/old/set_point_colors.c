/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:59:49 by irhett            #+#    #+#             */
/*   Updated: 2017/03/01 01:32:17 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define G (*grid)

static t_color	*get_color_from_spectrum(t_grid *grid, int row, int col)
{
	float			range;
	int				val;
	int				i;
	int				off;
	unsigned int	ret;

	if (G.cnum == 1)
		return (get_color_from_int(get_cint_from_color(G.c[0])));
	if (G.p[row][col].z == G.z_max)
		return (get_color_from_int(get_cint_from_color(G.c[G.cnum - 1])));
	range = G.z_max - G.z_min;
	off = (float)(range / (float)(G.cnum - 1));
	val = G.p[row][col].z - G.z_min;
	i = 1;
	while (i < G.cnum && (val >= (i * off)))
		i++;
	if (i < G.cnum)
		ret = gradient_color(G.c[i - 1], G.c[i], val - (i * off), off);
	else
		ret = gradient_color(G.c[i - 1], G.c[i - 1], val - (i * off), off);
	return (get_color_from_int(ret));
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