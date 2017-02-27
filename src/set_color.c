/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 21:38:58 by irhett            #+#    #+#             */
/*   Updated: 2017/02/26 16:21:33 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

unsigned int	set_color_from_chars(char a, char r, char g, char b)
{
	unsigned int	color;

	color = 0;
	color += (unsigned char)b;
	color += ((unsigned char)g * 256);
	color += ((unsigned char)r * 256 * 256);
	color += ((unsigned char)a * 256 * 256 * 256);
	return (color);
}

unsigned int	set_color(t_color *c)
{
	return (set_color_from_chars((*c).a, (*c).r, (*c).g, (*c).b));
}
