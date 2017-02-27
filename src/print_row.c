/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:40:47 by irhett            #+#    #+#             */
/*   Updated: 2017/02/26 16:15:28 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	print_row(int row, t_grid *grid)
{
	int		i;
	char	*str;

	i = 0;
	while (i < (*grid).width)
	{
		str = ft_itoa((*grid).p[row][i].z);
		ft_putstr(str);
		ft_putchar('\t');
		free(str);
		i++;
	}
	ft_putchar('\n');
}
