/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:13:18 by irhett            #+#    #+#             */
/*   Updated: 2017/02/26 14:57:35 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static void		row_error(t_grid *grid, int row, int col)
{
	while (--row >= 0)
	{
		while (--col >= 0)
		{
			if ((*grid).p[row][col].color)
				free((*grid).p[row][col].color);
		}
		free((*grid).p[row]);
		col = (*grid).width;
	}	
	free((*grid).p);
	exit(grid_error(grid, "initializing row in point array."));
}

void			read_grid(char *file, t_grid *grid)
{
	int		fd;
	int		row;
	int		col;
	char	*line;
	int		ret;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(grid_error(grid, "reopening file for data read."));
	(*grid).p = (t_point**)malloc(sizeof(t_point*) * (*grid).length);
	if (!(*grid).p)
		exit(grid_error(grid, "initializing greater point array."));
	row = 0;
	while (row < (*grid).length)
	{
		col = 0;
		(*grid).p[row] = (t_point*)malloc(sizeof(t_point) * (*grid).width);
		if (!(*grid).p[row])
			row_error(grid, row, 0);
		ft_bzero((*grid).p[row], sizeof(t_point) * (*grid).width); // ??
		ret = get_next_line(fd, &line);
		if (ret <= 0)
			row_error(grid, row + 1, 0);
		i = 0;
		while (col < (*grid).width)
		{
			(*grid).p[row][col].x = col;
			(*grid).p[row][col].y = row;
			(*grid).p[row][col].z = ft_atoi(&(line[i]));
			while (ft_isdigit(line[i]) || line[i] == '-')
				i++;
			if (line[i] == ',')
				i += str_to_color(&(line[i]), (*grid).p[row][col]);
			col++;
		}
		free(line);
		row++;
	}
}
