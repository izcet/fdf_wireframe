/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 21:37:41 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 19:57:14 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

static int		value_of(char c)
{
	if (ft_isdigit(c))
		return (c - 48);
	return (c - 55);
}

t_color			*str_to_color(char *str)
{
	t_color 	*c;

	c = (t_color*)malloc(sizeof(t_color));
	if (!c)
		return (NULL);
	ft_bzero(c, sizeof(t_color));
	str += 2;
	(*c).r += value_of(*(str++)) * 16;
	(*c).r += value_of(*(str++));
	(*c).g += value_of(*(str++)) * 16;
	(*c).g += value_of(*(str++));
	(*c).b += value_of(*(str++)) * 16;
	(*c).b += value_of(*(str++));
	return (c);
}
