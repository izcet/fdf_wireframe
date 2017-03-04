/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_win.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:57:48 by irhett            #+#    #+#             */
/*   Updated: 2017/03/02 13:18:08 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define W (*win)

t_win	*init_win(void)
{
	t_win	*win;

	win = (t_win*)malloc(sizeof(t_win));
	if (!win)
	{
		ft_error("Unable to allocate memory for t_win");
		return (NULL);
	}
	ft_bzero(win, sizeof(t_win));
	return (win);
}


// if win contains *data, then couldn't I just call *mlx from (*data).mlx?
void	del_win(t_win *win, void *mlx)
{
	if (win)
	{
		if (W.ptr)
		{
			if (mlx)
				mlx_destroy_window(mlx, W.ptr);
			free(W.ptr);
		}
		// free function pointers
		if (W.pos)
			del_xyzcp(W.pos);
		if (W.ang)
			del_xyzcp(W.ang);
		ft_bzero(win, sizeof(t_win));
		free(win);
		win = NULL;
	}
	else
		ft_error("Passed NULL to del_win()");
}
