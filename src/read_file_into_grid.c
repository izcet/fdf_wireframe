/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_into_grid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:58:23 by irhett            #+#    #+#             */
/*   Updated: 2017/02/28 11:16:35 by irhett           ###   ########.fr       */
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

static void		init_z_range(t_grid *grid, int val)
{
	(*grid).z_max = val;
	(*grid).z_min = val;
}

static int		point_set_color(char *str, t_grid *grid, int row, int col)
{
	(*grid).p[row][col].color = str_to_color(&(str[1]));
	return (9);
}

static void		read_row_data(int row, int col, char *line, t_grid *grid)
{
	int		i;

	i = 0;
	while (++col < (*grid).width)
	{
		while (line[i] == ' ')
			i++;
		(*grid).p[row][col].z = ft_atoi(&(line[i]));
		if (row + col == 0)
			init_z_range(grid, (*grid).p[row][col].z);
		else
		{
			if ((*grid).p[row][col].z > (*grid).z_max)
				(*grid).z_max = (*grid).p[row][col].z;
			if ((*grid).p[row][col].z < (*grid).z_min)
				(*grid).z_min = (*grid).p[row][col].z;
		}
		while (ft_isdigit(line[i]) || line[i] == '-')
			i++;
		if (line[i] == ',')
			i += point_set_color(&(line[i]), grid, row, col);
	}
	free(line);
}

void			read_file_into_grid(char *file, t_grid *grid)
{
	char	*line;
	int		ret;
	int		fd;
	int		row;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(grid_error(grid, "reopening file for data read."));
	(*grid).p = (t_zc**)malloc(sizeof(t_zc*) * (*grid).length);
	if (!(*grid).p)
		exit(grid_error(grid, "initializing greater point array."));
	row = -1;
	while (++row < (*grid).length)
	{
		(*grid).p[row] = (t_zc*)malloc(sizeof(t_zc) * (*grid).width);
		if (!(*grid).p[row])
			row_error(grid, row, 0);
		ft_bzero((*grid).p[row], sizeof(t_zc) * (*grid).width);
		ret = get_next_line(fd, &line);
		if (ret <= 0)
			row_error(grid, row + 1, 0);
		read_row_data(row, -1, line, grid);
	}
	close(fd);
}
