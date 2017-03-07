/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_col_from_range.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 21:20:53 by irhett            #+#    #+#             */
/*   Updated: 2017/03/06 22:01:36 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)
#define MAX D.z_max
#define MIN D.z_min
#define P (*D.map[row][col])
#define NCOL (D.num_col - 1)
#define RANGE (MAX - MIN)
#define VAL (P.z - MIN)
#define VAL100 (VAL * 100)

t_col	*get_col_from_range(t_data *data, int row, int col)
{
	int				i;
	int				off;
	unsigned int	cint;

	if (D.num_col == 1 || P.z == MIN)
		return (make_col_from_int(get_int_from_col(D.col[0])));
	if (P.z == MAX)
		return (make_col_from_int(get_int_from_col(D.col[NCOL])));
	off = ((100 * RANGE) / (NCOL));
	i = 1;
	while (i < NCOL && (VAL100 >= (i * off)))
		i++;
	cint = gradient_col(D.col[i - 1], D.col[i], VAL100 - ((i - 1) * off), off);
	return (make_col_from_int(cint));
}
