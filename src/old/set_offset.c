/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:26:33 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 20:31:11 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	set_offset(t_grid *grid, t_data *data)
{
	if ((*grid).width > (*grid).length)
		(*(*data).win).scale = WINDOW_SIZE / ((*grid).width + 2);
	else
		(*(*data).win).scale = WINDOW_SIZE / ((*grid).length + 2);
}
