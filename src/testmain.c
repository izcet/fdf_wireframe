/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:49:29 by irhett            #+#    #+#             */
/*   Updated: 2017/03/06 22:01:33 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"
#include <stdio.h>

#define D (*data)
#define M (*D.map)
#define P (*M[row][col].c)

int		main(int argc, char **argv)
{
	t_data	*data;
	int		row;
	int		col;

	printf("STARTING\n");
	data = init_data();
	printf("Data initialized\n");
	D.wid = 3;
	D.len = 2;
	D.map = init_zcp_2d_arr(D.len, D.wid);
	printf("Map initialized\n");
	row = -1;
	while (++row < D.len)
	{
		col = -1;
		while (++col < D.wid)
			M[row][col].z = (row + col);
	}
	printf("Map points set.\n");
	if (set_point_cols(data, argc, argv))
		printf("ERROR\n");
	printf("Point colors set.\n");
	row = -1;
	while (++row < D.len)
	{
		printf("\n\trow %i:\n", row);
		col = -1;
		while (++col < D.wid)
		{
			printf("%i\n", col);
			printf("Point[%i][%i].c.a = [%u]\n", row, col, P.a);
			printf("Point[%i][%i].c.r = [%u]\n", row, col, P.r);
			printf("Point[%i][%i].c.g = [%u]\n", row, col, P.g);
			printf("Point[%i][%i].c.b = [%u]\n\n", row, col, P.b);
		}
	}
	del_data(data);
	(void)argc;
	(void)argv;
	return (0);
}
