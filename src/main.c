/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:16:33 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 03:25:35 by irhett           ###   ########.fr       */
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
	if (!is_valid_file(argv[1], grid))
		return (1);
	read_file_into_grid(argv[1], grid);
	print_grid(grid);
	data = init_data(argv[1], grid, NULL);
	if (!data)
		return (0);
	t_xy *a = malloc(sizeof(t_xy));
	ft_bzero(a, sizeof(t_xy));
	t_xy *b = malloc(sizeof(t_xy));
	ft_bzero(b, sizeof(t_xy));
	t_color *c = malloc(sizeof(t_color));
	ft_bzero(c, sizeof(t_color));


	(*a).x = 400;
	(*a).y = 100;
	(*b).x = 300;
	(*b).y = 500;
	(*c).r = 200;
	(*c).g = 200;

	draw_line(b, a, c, data);
	/*unsigned char x = 0;
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
	}*/
	mlx_key_hook((*(*data).win).ptr, key_pressed, data);
	mlx_loop((*data).mlx);
	(void)argc;
	(void)argv;
}
