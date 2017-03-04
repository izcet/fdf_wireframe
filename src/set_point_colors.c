/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:52:46 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 21:06:16 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)

void		set_z_range(t_data *data)
{
	int		row;
	int		col;

	row = -1;
	while (++row < D.len)
	{
		col = -1;
		while (++col < D.wid)
		{
			if (row + col == 0)
			{
				D.z_min = D.map[row][col].z;
				d.z_max = D.map[row][col].z;
			}
			else
			{
				if (D.z_min > D.map[row][col].z)
					D.z_min = D.map[row][col].z;
				if (D.z_max < D.map[row][col].z)
					D.z_max = D.map[row][col].z;
			}
		}
	}
}

void			set_point_colors(t_data *data, int argc, char **argv)
{
	set_z_range(data);
	D.col = make_color_1d_arr(int argc, char **argv);
	//read range
	//check colors from stdin

	//setting point colors requires color arr and range
}
