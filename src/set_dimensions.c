/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:27:42 by irhett            #+#    #+#             */
/*   Updated: 2017/02/24 23:13:00 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static int	get_num(char *str)
{
	int		num;

	num = 0;
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
					str += 10;
				else
					return (-1);
			}
		}
		else
			return (-1);
		num++;
		if (*str && !ft_isspace(*str))
			return (-1);
		while (*str && ft_isspace(*str))
			str++;
	}
	return (num);
}

static int		read_file_dimen(int fd, t_grid *grid)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((*grid).length == 0)
		{
			(*grid).width = get_num(line);
			free(line);
			if ((*grid).width == -1)
				return (grid_error(grid, "invalid file (first line)."));
		}
		else
		{
			free(line);
			if (get_num(line) != (*grid).width)
				return (grid_error(grid, "invalid file."));
		}
		(*grid).length++;
	}
	if (ret < 0)
		return (grid_error(grid, "reading from file."));
	return (0);
}

int		set_dimensions(char *file, t_grid *grid)
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
