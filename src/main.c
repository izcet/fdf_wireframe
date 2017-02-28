/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:16:33 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 21:24:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

int		main(int argc, char **argv)
{
	t_data	*data;
	t_grid	*grid;

	if (argc < 2) // modify to also allow colors as input parameters
		return (ft_usage(argv[0], " <filename> [color min...max]"));
	grid = init_grid();
	if (!grid)
		return (ft_error("allocating space for the grid."));
	if (!is_valid_file(argv[1], grid))
		return (1);
	read_file_into_grid(argv[1], grid);
	print_grid(grid);
	data = init_data(argv[1], grid, NULL);
	if (!data)
		return (0);
	(*grid).cols = read_colors(argc, argv, grid);
	set_point_colors(grid);
	set_offset(grid, data);
	draw_grid(grid, data);


	mlx_key_hook((*(*data).win).ptr, key_pressed, data);
	mlx_loop((*data).mlx);
	(void)argc;
	(void)argv;
}
