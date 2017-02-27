/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 22:17:59 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 03:26:20 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_R 15

#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_F 3

#define KEY_Z 6
#define KEY_X 7
#define KEY_C 8
#define KEY_V 9

#define KEY_ESC 53

int		key_pressed(int keycode, void *ptr)
{
	char	*str;
	t_data	*data;

	data = (t_data*)ptr;
	str = ft_itoa(keycode);
	ft_putstr("Keycode is ");
	ft_putendl(str);
	free(str);
	if (keycode == KEY_ESC)
		close_win(data);
	return (0);
}
