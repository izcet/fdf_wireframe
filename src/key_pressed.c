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

#define W (*win)

static void		handle_local_adjustments(t_win *win, int keycode)
{
	if (keycode == KEY_Z)
		W.center_x -= MOVE_OFF;
	else if (keycode == KEY_X)
		W.center_y += MOVE_OFF;
	else if (keycode == KEY_C)
		W.center_y -= MOVE_OFF;
	else if (keycode == KEY_V)
		W.center_x += MOVE_OFF;
	else if (keycode == KEY_F && W.scale > SCALE_OFF)
		W.scale -= SCALE_OFF;
	else if (keycode == KEY_R)
		W.scale += SCALE_OFF;
}

int		key_pressed(int keycode, void *ptr)
{
	char	*str;
	t_win	*win;

	win = (t_win*)ptr;
	//
	str = ft_itoa(keycode);
	ft_putstr("Keycode is ");
	ft_putendl(str);
	free(str);
	//
	if (keycode == KEY_ESC)
	{
		del_data(W.data);
		exit(0);
	}
	else if (keycode == KEY_Q)
		rotate_grid_x_pos(W.data);
	else if (keycode == KEY_A)
		rotate_grid_x_neg(W.data);
	else if (keycode == KEY_W)
		rotate_grid_y_pos(W.data);
	else if (keycode == KEY_S)
		rotate_grid_y_neg(W.data);
	else if (keycode == KEY_E)
		rotate_grid_z_pos(W.data);
	else if (keycode == KEY_D)
		rotate_grid_z_neg(W.data);
	else
		handle_local_adjustments(win, keycode);
	return (0);
}
