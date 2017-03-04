/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_z_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:06:33 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 21:07:29 by irhett           ###   ########.fr       */
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
