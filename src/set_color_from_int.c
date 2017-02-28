/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_from_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:26:09 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 19:36:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_color		*set_color_from_int(unsigned int c)
{
	t_color		*col;

	col = (t_color*)malloc(sizeof(t_color));
	if (!col)
		return (NULL);
	ft_bzero(col, sizeof(t_color));
	(*col).b = (c % 256);
	c = c / 256;
	(*col).g = (c % 256);
	c = c / 256;
	(*col).r = (c % 256);
	c = c / 256;
	(*col).a = (c % 256);
	return (col);
}
