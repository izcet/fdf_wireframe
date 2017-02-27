/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 01:11:02 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 01:48:38 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static t_data	*derr(char *msg, void *grid, void *ptr2, void *ptr3)
{
	ft_error(msg);
	free_grid(grid);
	if (ptr2)
		free(ptr2);
	ptr2 = NULL;
	if (ptr3)
		free(ptr3);
	ptr3 = NULL;
	return ((t_data*)NULL);
}

t_data			*init_data(char *title, t_grid *ptr, t_color **color_arr)
{
	t_data	*d;

	d = (t_data*)malloc(sizeof(t_data));
	if (!d)
		return (derr("allocating memory for data struct.", ptr, 0, 0));
	ft_bzero(d, sizeof(t_data));
	(*d).mlx = mlx_init();
	if (!(*d).mlx)
		return (derr("initializing the mlx pointer.", ptr, d, 0));
	(*d).win = init_window(title, (*d).mlx);
	if (!(*d).win)
		return (derr("initializing the window struct.", ptr, (*d).mlx, d));
	(*d).grid = ptr;
	(void)color_arr;
	return (d);
}
