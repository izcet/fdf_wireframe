/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:16:33 by irhett            #+#    #+#             */
/*   Updated: 2017/02/26 01:53:06 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

/*int		my_key_funct(int keycode, void *param)
{
	char	*str;

	str = ft_itoa(keycode);
	ft_putstr("Keycode is ");
	ft_putendl(str);
	free(str);
	(void)param;
	return (0);

}*/

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
	read_grid(argv[1], grid);
	//read file into struct
	data = init_window(400, 400, "test window");
	if (!data)
		return (0);
	unsigned char x = 0;
	while (x < 255)
	{
		unsigned char y = 0;
		while (y < 255)
		{
			//unsigned int c1 = set_color_from_chars(0, 0, y, (x + y) / 2);
			unsigned int c2 = set_color_from_chars(200, x, 0, 0);
			unsigned int c3 = set_color_from_chars(200, 0, x, 0);
//			mlx_pixel_put((*data).mlx,(*data).win, x, y, color);
			mlx_pixel_put((*data).mlx,(*data).win, x, x, c2);
			mlx_pixel_put((*data).mlx,(*data).win, 256 - x, x, c3);
			y++;
		}
		x++;
	}
	mlx_key_hook((*data).win, key_pressed, 0);
	mlx_loop((*data).mlx);

	(void)argc;
	(void)argv;
}
