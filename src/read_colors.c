/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:15:43 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 19:35:38 by irhett           ###   ########.fr       */
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
	the_colors[0] = set_color_from_int(COLOR_MAX);
	the_colors[1] = set_color_from_int(COLOR_MID);
	the_colors[2] = set_color_from_int(COLOR_MIN);
	(*grid).num_cols = 3;
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
			return (0);
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
		return (init_default(grid));
	c = (t_color**)malloc(sizeof(t_color*) * argc - i);
	if (!c)
		return (NULL);
	ft_bzero(c, (sizeof(t_color*) * 3));
	while (i < argc)
	{
		c[i - 2] = str_to_color(argv[i]);
		i++;
	}
	(*grid).num_cols = (argc - 2);
	return (c);
}
