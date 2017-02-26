/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:31:41 by irhett            #+#    #+#             */
/*   Updated: 2017/02/25 22:25:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static t_data	*werr(char *msg, void *ptr1, void *ptr2, void *ptr3)
{
	ft_error(msg);
	if (ptr1)
		free(ptr1);
	ptr1 = NULL;
	if (ptr2)
		free(ptr2);
	ptr2 = NULL;
	if (ptr3)
		free(ptr3);
	ptr3 = NULL;
	return ((t_data*)NULL);
}

t_data			*init_window(int width, int height, char *title)
{
	t_data	*d;

	d = (t_data*)malloc(sizeof(t_data));
	if (!d)
		return (werr("allocating the struct pointer.", 0, 0, 0));
	ft_bzero(d, sizeof(d));
	(*d).mlx = mlx_init();
	if (!(*d).mlx)
		return (werr("initializing the mlx pointer.", d, 0, 0));
	(*d).win = mlx_new_window((*d).mlx, width, height, title);
	if (!(*d).win)
		return (werr("making a new window.", (*d).mlx, d, 0));
	(*d).win_width = width;
	(*d).win_height = height;
	(*d).win_title = gnl_concat(title, "", 0, 0);
	if (!(*d).win_title)
		return (werr("saving the title variable????", (*d).win, (*d).mlx, d));
	return (d);
}
