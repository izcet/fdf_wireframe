/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:16:33 by irhett            #+#    #+#             */
/*   Updated: 2017/02/26 18:58:10 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

int		main(int argc, char **argv)
{
	t_data	*data;
	t_grid	*grid;

	if (argc != 2) // modify to also allow colors as input parameters
		return (ft_usage(argv[0], " <filename>"));
	grid = init_grid();
	if (!grid)
		return (ft_error("allocating space for the grid."));
	if (set_dimensions(argv[1], grid))
		return (1);
	read_file_into_grid(argv[1], grid);
	/*ft_putendl(ft_itoa((*grid).width));
	ft_putendl(ft_itoa((*grid).length));
	int i = 0;
	while (i < (*grid).length)
		print_row(i++, grid);*/

	// fix up beyond this point. data structure should contain window structure
	data = init_window(400, 400, "test window");
	if (!data)
		return (0);
	(*data).grid = grid;
	unsigned char x = 0;
	while (x < 255)
	{
		unsigned char y = 0;
		while (y < 255)
		{
			//unsigned int c1 = set_color_from_chars(0, 0, y, (x + y) / 2);
			unsigned int c2 = set_color_from_chars(200, x, 0, 0);
			//unsigned int c3 = set_color_from_chars(200, 0, x, 0);
			//mlx_pixel_put((*data).mlx,(*data).win, x, y, color);
			//if (x % 200 == 0)
				//mlx_string_put((*data).mlx,(*data).win, 256 - x, x, c3, "s");
			mlx_pixel_put((*data).mlx,(*data).win, x, x, c2);
			y++;
		}
		x++;
	}
	mlx_key_hook((*data).win, key_pressed, data);
	mlx_loop((*data).mlx);
	(void)argc;
	(void)argv;
}
