/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point_by_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 00:23:21 by irhett            #+#    #+#             */
/*   Updated: 2017/03/11 00:39:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define P (*p)
#define T (*t)
#define D T.data
#define X P.x
#define Y P.y
#define Z P.z

void	rotate_point_by_matrix(t_xyzcp *p, t_int_matrix *t)
{
	int	w; // or float? // should I keep it?
	float	x;
	float	y;
	float	z;

	if (p && t)
	{
		if (T.rows == 4 && T.cols == 4)
		{
			x = (X * D[0][0]) + (Y * D[1][0]) + (Z * D[2][0]) + D[3][0];
			y = (X * D[0][1]) + (Y * D[1][1]) + (Z * D[2][1]) + D[3][1];
			z = (X * D[0][2]) + (Y * D[1][2]) + (Z * D[2][2]) + D[3][2];
			w = (X * D[0][3]) + (Y * D[1][3]) + (Z * D[2][3]) + D[3][3];
			if (w != 1 && w != 0)
			{
				x = x / w;
				y = y / w;
				z = z / w;
			}
			set_xyzcp(p, x, y, z);
		}
		else
			ft_error("Invalid matrix dimensions in rotate_point_by_matrix()");
	}
	else
		ft_error("NULL passed to rotate_point_by_matrix()");
}
