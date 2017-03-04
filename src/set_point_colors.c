/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:52:46 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 22:48:43 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)

static int		fill_point_colors(t_data *data)
{
	int		row;
	int		col;
	t_col	*c;

	row = -1;
	while (++row < D.len)
	{
		col = -1;
		while (++col < D.wid)
		{
			if (!D.map[row][col].c)
			{
				c = get_color_from_range(data, row, col);
				if (c)
					D.map[row][col].c = c;
				else
					return (1);
			}
		}
	}
	return (0);
}

int			set_point_colors(t_data *data, int argc, char **argv)
{
	set_z_range(data);
	D.col = make_color_1d_arr(data, argc, argv);
	if (!D.col)
		return (1);
	return (fill_point_colors(data));
}
