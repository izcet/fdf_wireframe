/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 01:32:35 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 01:58:22 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define GR (*grid)

void		free_grid(t_grid *grid)
{
	int		row;
	int		col;

	row = 0;
	while (row < GR.length)
	{
		col = 0;
		while (col < GR.width)
		{
			if (GR.p[row][col].color)
				free(GR.p[row][col].color);
			col++;
		}
		free(GR.p[row]);
		row++;
	}
	free(GR.p);
	free(grid);
}
