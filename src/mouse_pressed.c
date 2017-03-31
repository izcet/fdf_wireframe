/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pressed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:09:14 by irhett            #+#    #+#             */
/*   Updated: 2017/03/01 20:16:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"
#include <stdio.h>

int		mouse_pressed(int button, int x, int y, void *param)
{
	ft_putendl("Mouse clicked.");
	printf("X: %i, Y: %i, Button: %i\n", x, y, button);
	(void)param;
	return (0);
}
