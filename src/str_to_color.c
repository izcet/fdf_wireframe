/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 21:37:41 by irhett            #+#    #+#             */
/*   Updated: 2017/02/25 21:37:52 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define STR *(str++)
#define SET += value_of(STR)

static int		value_of(char c)
{
	if (ft_isdigit(c))
		return (c - 48);
	return (c - 55);
}

int				str_to_color(char *str, t_point point)
{
	point.color = (t_color*)malloc(sizeof(t_color));
	ft_bzero(point.color, sizeof(t_color));
	str += 3;
	(*point.color).r SET * 16;
	(*point.color).r SET;
	(*point.color).g SET * 16;
	(*point.color).g SET;
	(*point.color).b SET * 16;
	(*point.color).b SET;
	return (9);
}
