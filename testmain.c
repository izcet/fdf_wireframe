/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:49:29 by irhett            #+#    #+#             */
/*   Updated: 2017/03/07 11:22:43 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"
#include <stdio.h>

#define D (*data)
#define M (D.map)
#define P (*M[r][col]) 
#define C (*P.c)

int		main(int argc, char **argv)
{
	t_data	*data;
	int		r;
	int		col;

	printf("STARTING\n");
	data = init_data();
	printf("Data initialized\n");
	D.wid = 9;
	D.len = 9;
	D.map = init_zcp_2d_arr(D.len, D.wid);
	printf("Map initialized\n");
	r = -1;
	while (++r < D.len)
	{
		col = -1;
		while (++col < D.wid)
		{
			//printf("row %i col %i\n", r, col);
			P.z = (r + col);
			//printf("val %i\n", P.z);
		}
	}
	printf("Map points set.\n");
	if (set_point_cols(data, argc, argv))
		printf("ERROR\n");
	printf("point colors set.\n");
	r = -1;
	while (++r < D.len)
	{
		printf("\nrow %i:\n", r);
		col = -1;
		while (++col < D.wid)
		{

			printf("col %i (%i)\n", col, P.z);
			printf("[%i][%i] = [%u][%u][%u][%u]\n", r, col, C.a, C.r, C.g, C.b);
		}
	}
	del_data(data);
	(void)argc;
	(void)argv;
	return (0);
}
