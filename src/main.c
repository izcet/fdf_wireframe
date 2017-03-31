/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:16:33 by irhett            #+#    #+#             */
/*   Updated: 2017/03/08 15:58:32 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data)

int		cleanup(t_data *data, int ret)
{
	del_data(data);
	return (ret);
}

int		main(int argc, char **argv)
{
	t_data	*data;
	t_xyp	*dimen;

	if (argc < 2)
		return (ft_usage(argv[0], " <filename> [color min...max]"));
	data = init_data();
	if (!data)
		return (ft_error("Unable to allocate space for main memory struct."));
	dimen = parse_file(argv[1]);
	if (!dimen)
		return (cleanup(data, 1));
	set_data_xy(data, dimen);
	if (populate_map(data, argv[1]) != 0)
		return (cleanup(data, 1));
	if (set_point_cols(data, argc, argv) != 0)
		return (cleanup(data, 1));
	print_data_map(data);
	if (make_3d_map_from_zcp(data))
	{
		D.num_win = 3;
		D.win = init_win_1d_arr(D.num_win);
		set_win(data, 800, 800, D.win[0]);
		set_win(data, 1000, 1000, D.win[1]);
		set_win(data, WINDOW_SIZE, WINDOW_SIZE, D.win[2]);
		set_window_hooks(data);
		//draw_grid(grid, data, -1, -1);
		//mlx_key_hook((*(*data).win).ptr, key_pressed, data);
		//mlx_mouse_hook((*(*data).win).ptr, mouse_pressed, data);
		mlx_loop((*data).mlx);
	}
	return (cleanup(data, 0));
}
