/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_from_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:49:22 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 22:57:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)

t_col	*get_color_from_range(t_data *data, int row, int col)
{
	float			range;
	int				val;
	int				i;
	int				off;
	unsigned int	ret;

	if (D.cnum == 1)
		return (get_color_from_int(get_cint_from_color(D.c[0])));
	if (D.p[row][col].z == D.z_max)
		return (get_color_from_int(get_cint_from_color(D.c[D.cnum - 1])));
	range = D.z_max - D.z_min;
	off = (float)(range / (float)(D.cnum - 1));
	val = D.p[row][col].z - D.z_min;
	i = 1;
	while (i < D.cnum && (val >= (i * off)))
		i++;
	if (i < D.cnum)
		ret = gradient_color(D.c[i - 1], D.c[i], val - (i * off), off);
	else
		ret = gradient_color(D.c[i - 1], D.c[i - 1], val - (i * off), off);
	return (get_color_from_int(ret));
}
