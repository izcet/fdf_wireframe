/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:13:18 by irhett            #+#    #+#             */
/*   Updated: 2017/02/24 23:14:45 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static void		row_error(t_grid *grid, int row, int col)
{
	while (--row >= 0)
	{
		while (--col >= 0)
		{
			if ((*grid).points[row][col].color)
				free((*grid).points[row][col].color);
		}
		free((*grid).points[row]);
		col = (*grid).width;
	}	
	free((*grid).points);
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
	(*grid).points = (t_point**)malloc(sizeof(t_point*) * (*grid).length);
	if (!(*grid).points)
		exit(grid_error(grid, "initializing greater point array."));
	row = 0;
	while (row < (*grid).length)
	{
		col = 0;
		(*grid).points[row] = (t_point*)malloc(sizeof(t_point) * (*grid).width);
		if (!(*grid).points[row])
			row_error(grid, row, 0);
		ft_bzero((*grid).points[row], sizeof(t_point) * (*grid).width); // ??
		ret = get_next_line(fd, &line);
		if (get_next_line <= 0)
			row_error(grid, row + 1, 0);
		i = 0;
		while (col < (*grid).width)
		{
			(*grid).points[row][col].x = col;
			(*grid).points[row][col].y = row;
			(*grid).points[row][col].z = ft_atoi(&(line[i]));
			while (ft_isdigit(line[i]) || line[i] == '-')
				i++;
			if (line[i] == ',')
				i += set_color(&(line[i]), (*grid).points[row][col]);
			col++;
		}
		free(line);
		row++;
	}
}
