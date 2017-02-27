/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:29:30 by irhett            #+#    #+#             */
/*   Updated: 2017/02/26 18:58:13 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define DT (*data)
#define GR (*grid)

static void		free_grid(t_grid *grid)
{
	int		row;
	int		col;

	row = 0;
	while (row < GR.length)
	{
		col = 0;
		while (col < GR.width)
		{
			char *str = ft_itoa(col);
			ft_putendl(str);
			free(str);
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

void			close_win(t_data *data)
{
	mlx_destroy_window((*data).mlx, (*data).win);
	free(DT.mlx);
	free(DT.win_title);
	free_grid((*data).grid);
	free(data);
	exit(0);
}
