/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:16:33 by irhett            #+#    #+#             */
/*   Updated: 2017/03/06 01:03:56 by irhett           ###   ########.fr       */
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






	print_grid(grid); ///
	data = init_data(argv[1], grid, NULL);
	if (!data)
		return (0);

	(*grid).c = read_colors(argc, argv, grid);
	set_point_colors(grid);
	set_offset(grid, data);
	draw_grid(grid, data, -1, -1);
	mlx_key_hook((*(*data).win).ptr, key_pressed, data);
	mlx_mouse_hook((*(*data).win).ptr, mouse_pressed, data);
	mlx_loop((*data).mlx);
	(void)argc;
	(void)argv;
}
