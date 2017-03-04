/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:00:45 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 18:58:08 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static int		point_set_color(t_zcp *p, char *str)
{
	(*p).color = make_col_from_str(str + 1);
	return (9);
}

static void		fill_row(t_zcp **p, int wid, char *str)
{
	int		i;

	i = -1;
	while (++i < wid)
	{ 
		while (*str == ' ')
			str++;
		p[i].z = ft_atoi(str);
		while ((ft_isdigit(*str)) || (*str == '-'))
			str++;
		if (*str == ',')
			str += point_set_color(p[i], str);
	}
}

static t_zcp	***make_zcp_2d_arr(int fd, int len, int wid)
{
	t_zcp	***p;
	char	*line;
	int		row;
	int		col;
	int		br;

	p = init_zcp_2d_arr(len, wid);
	if (!p)
		return (NULL);
	row = -1;
	while (++row < D.len)
	{
		br = get_next_line(fd, &line);
		if (br < 0)
		{
			del_zcp_2d_arr(p, row, wid);
			return (NULL);
		}
		fill_row(p[row], wid, line);
		free(line);
	}
	return (p);
}

int				populate_map(t_data *data, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error("Unable to reopen file."));
	if (!data)
		return (ft_error("NULL pointer passed to populate_map()"));
	D.map = make_zcp_2d_arr(fd, D.len, D.wid);
	close(fd);
	if (!D.map)
		return (1);
	return (0);
}