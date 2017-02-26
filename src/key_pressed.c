/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 22:17:59 by irhett            #+#    #+#             */
/*   Updated: 2017/02/26 00:31:43 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

/*
 * shift up, left, down, right respectively
 */
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

/*
 * rotate around z axis, counter and clockwise respectively
 */
#define KEY_Q 12
#define KEY_E 14

/* 
 * rotate around x axis, rolling away and towards, respectively
 */
#define KEY_R 15
#define KEY_F 3

/*
 * rotate around y axis, counter earth and earthlike respectively
 */
#define KEY_Z 6
#define KEY_X 7

/*
 * shift towards and away, respectively
 * or do I want to make it zoom in/out?
 *
 */
#define KEY_C 8
#define KEY_V 9

/*
 * exit the program
 */
#define KEY_ESC 53


int		key_pressed(int keycode, void *param)
{	
	t_data	*data;
	char	*str;

	str = ft_itoa(keycode);
	ft_putstr("Keycode is ");
	ft_putendl(str);
	free(str);
	data = (t_data*)param;
	return (0);
}
