/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:16:33 by irhett            #+#    #+#             */
/*   Updated: 2017/02/27 19:57:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

int		main(int argc, char **argv)
{
	t_data	*data;
	t_grid	*grid;

	if (argc != 2) // modify to also allow colors as input parameters
		return (ft_usage(argv[0], " <filename> [color max .... min]"));
	grid = init_grid();
	if (!grid)
		return (ft_error("allocating space for the grid."));
	if (!is_valid_file(argv[1], grid))
		return (1);
	ft_putendl("A");
	read_file_into_grid(argv[1], grid);
	ft_putendl("B");
	//erroring somewhere between here
	print_grid(grid);
	ft_putendl("C");
	
	data = init_data(argv[1], grid, NULL);
	if (!data)
		return (0);
	(*grid).cols = read_colors(argc, argv, grid);






	t_xy *a = malloc(sizeof(t_xy));
	ft_bzero(a, sizeof(t_xy));

	t_xy *b = malloc(sizeof(t_xy));
	ft_bzero(b, sizeof(t_xy));
	
	t_color *ac = malloc(sizeof(t_color));
	ft_bzero(ac, sizeof(t_color));

	t_color *bc = malloc(sizeof(t_color));
	ft_bzero(bc, sizeof(t_color));

	(*b).x = 500;
	(*b).y = 500;
	(*b).color = bc;

	(*ac).r = 200;
	//(*ac).g = 100;
	//(*ac).b = 100;

	//(*bc).r = 100;
	(*bc).b = 250;

	draw_line(b, a, data);
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
