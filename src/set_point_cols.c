/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_cols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 21:15:36 by irhett            #+#    #+#             */
/*   Updated: 2017/03/06 22:01:46 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"
#include <stdio.h>

#define D (*data)
#define P D.map[row][col]

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
			printf("\t[%i][%i]\n", row, col);
			if (!(*P).c)
			{
				
				c = get_col_from_range(data, row, col);
				printf("\t\t[%u]\n", (*c).r);
				if (c)
					(*P).c = c;
				else
					return (1);
			}
		}
	}
	return (0);
}

int			set_point_cols(t_data *data, int argc, char **argv)
{
	set_z_range(data);
	printf("z range set\n");
	D.col = make_col_1d_arr(data, argc, argv);
	printf("Make_col_1d_arr() done\n");
	if (!D.col)
		return (1);
	return (fill_point_colors(data));
}
