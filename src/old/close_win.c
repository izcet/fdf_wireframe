/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:29:30 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 01:45:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void			close_win(t_data *data)
{
	mlx_destroy_window((*data).mlx, (*(*data).win).ptr);
	free_win((*data).win);
	free_grid((*data).grid);
	free((*data).mlx);
	free(data);
	exit(0);
}
