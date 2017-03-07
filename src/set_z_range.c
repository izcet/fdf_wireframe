/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_z_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:06:33 by irhett            #+#    #+#             */
/*   Updated: 2017/03/06 21:45:42 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"
#include <stdio.h>

#define D (*data)
#define P D.map[row][col]

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
			printf("[%i][%i]\n", row, col);
			if (row + col == 0)
			{
				D.z_min = (*P).z;
				D.z_max = (*P).z;
			}
			else
			{
				if (D.z_min > (*P).z)
					D.z_min = (*P).z;
				if (D.z_max < (*P).z)
					D.z_max = (*P).z;
			}
		}
	}
}
