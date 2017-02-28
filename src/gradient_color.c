/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:10:10 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 21:11:03 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define A (*a)
#define B (*b)

static unsigned char	get_char_v(unsigned char a, unsigned char b, int v, int r)
{
	float			c1;
	float			c2;

	c1 = ((float)(a) * (float)((float)(r - v) / (float)(r)));
	c2 = (float)((float)(b) * (float)((float)(v) / (float)(r)));
	if ((unsigned char)(c1 + c2) > 255)
		return (255);
	if ((unsigned char)(c1 + c2) < 0)
		return (0);
	return ((unsigned char)(c1 + c2));
}

unsigned int	gradient_color(t_color *a, t_color *b, int v, int r)
{
	unsigned char	fa;
	unsigned char	fr;
	unsigned char	fg;
	unsigned char	fb;

	fa = get_char_v(A.a, B.a, v, r);
	fr = get_char_v(A.r, B.r, v, r);
	fg = get_char_v(A.g, B.g, v, r);
	fb = get_char_v(A.b, B.b, v, r);
	return (set_color_from_chars(fa, fr, fg, fb));
}
