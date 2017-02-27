/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 02:00:40 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 02:04:52 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define ORNOT else return (0)

static int	get_num(char *str, int num)
{
	if (!ft_isdigit(*str) && (*str != '-'))
		return (-1);
	while (*str)
	{
		if (*str == '-')
			str++;
		if (ft_isdigit(*str))
		{
			while (*str && ft_isdigit(*str))
				str++;
			if (*str == ',')
			{
				if (is_valid_color((++str)))
					str += 8;
				ORNOT;
			}
		}
		ORNOT;
		num++;
		if (*str && !ft_isspace(*str))
			return (0);
		while (*str && ft_isspace(*str))
			str++;
	}
	return (num);
}

static int	read_file_dimen(int fd, t_grid *grid)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((*grid).length == 0)
		{
			(*grid).width = get_num(line, 0);
			free(line);
			if ((*grid).width <= 0)
				return (grid_error(grid, "invalid file (first line).") && 0);
		}
		else
		{
			free(line);
			if (get_num(line, 0) != (*grid).width)
				return (grid_error(grid, "invalid file.") && 0);
		}
		(*grid).length++;
	}
	if (ret < 0)
		return (grid_error(grid, "reading from file.") && 0);
	return (1);
}

int			is_valid_file(char *file, t_grid *grid)
{
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (grid_error(grid, "opening file."));
	ret = read_file_dimen(fd, grid);
	close(fd);
	return (ret);
}
