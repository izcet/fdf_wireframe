/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:31:41 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 01:49:16 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_win			*init_window(char *title, void *mlx)
{
	t_win	*win;

	win = (t_win*)malloc(sizeof(t_win));
	if (!win)
		return (NULL);
	ft_bzero(win, sizeof(t_win));
	(*win).ptr = mlx_new_window(mlx, WINDOW_SIZE, WINDOW_SIZE, title);
	if (!(*win).ptr)
	{
		free(win);
		return (NULL);
	}
	(*win).title = gnl_concat(title, "", 0, 0);
	if (!(*win).title)
	{
		free(win);
		return (NULL);
	}
	return (win);
}
