/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 01:35:00 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 03:26:32 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	print_grid(t_grid *grid)
{
	int		i;

	i = 0;
	ft_putendl(ft_itoa((*grid).width));
	ft_putendl(ft_itoa((*grid).length));
	while (i < (*grid).length)
		print_row(i++, grid);
}
