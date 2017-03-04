/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:15:43 by irhett            #+#    #+#             */
/*   Updated: 2017/03/01 01:33:57 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static t_color		**init_default(t_grid *grid)
{
	t_color		**the_colors;

	the_colors = (t_color**)malloc(sizeof(t_color*) * 3);
	if (!the_colors)
		return (NULL);
	ft_bzero(the_colors, (sizeof(t_color*) * 3));
	the_colors[0] = get_color_from_int(COLOR_MIN);
	the_colors[1] = get_color_from_int(COLOR_MID);
	the_colors[2] = get_color_from_int(COLOR_MAX);
	(*grid).cnum = 3;
	return (the_colors);
}

static int			valid_args(int argc, char **argv)
{
	int		i;

	i = 2;
	if (argc == 2)
		return (0);
	while (i < argc)
	{
		if (!is_valid_color(argv[i]))
		{
			ft_putendl("Invalid color arguments.");
			return (0);
		}
		i++;
	}
	return (1);
}

t_color				**read_colors(int argc, char **argv, t_grid *grid)
{
	t_color		**c;
	int			i;

	i = 2;
	if (!valid_args(argc, argv))
	{
		return (init_default(grid));
	}
	c = (t_color**)malloc(sizeof(t_color*) * (argc - i));
	if (!c)
		return (NULL);
	ft_bzero(c, (sizeof(t_color*) * (argc - i)));
	while (i < argc)
	{
		c[i - 2] = get_color_from_str(argv[i]);
		i++;
	}
	(*grid).cnum = (argc - 2);
	return (c);
}
