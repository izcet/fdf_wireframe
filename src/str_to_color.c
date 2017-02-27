/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 21:37:41 by irhett            #+#    #+#             */
/*   Updated: 2017/02/26 16:47:04 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static int		value_of(char c)
{
	if (ft_isdigit(c))
		return (c - 48);
	return (c - 55);
}

int				str_to_color(char *str, t_zc point)
{
	point.color = (t_color*)malloc(sizeof(t_color));
	ft_bzero(point.color, sizeof(t_color));
	str += 3;
	(*point.color).r += value_of(*(str++)) * 16;
	(*point.color).r += value_of(*(str++));
	(*point.color).g += value_of(*(str++)) * 16;
	(*point.color).g += value_of(*(str++));
	(*point.color).b += value_of(*(str++)) * 16;
	(*point.color).b += value_of(*(str++));
	return (9);
}
