/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:06:20 by irhett            #+#    #+#             */
/*   Updated: 2017/02/24 13:18:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"



t_grid	*read_file(char *filename)
{
	int			fd;
	char		*line;
	int			ret;
	t_grid		*grid;

	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(ft_error("opening file."));
	while ((ret = get_next_line(fd, &line)) > 0)
	{

	}
	close(fd);
	if (ret < 0)
		exit(ft_error("reading from file."));
	//check_grid
	//return grid if valid
}
