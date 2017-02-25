/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:16:33 by irhett            #+#    #+#             */
/*   Updated: 2017/02/24 20:09:21 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

int		my_key_funct(int keycode, void *param)
{
	char	*str;

	str = ft_itoa(keycode);
	ft_putstr("Keycode is ");
	ft_putendl(str);
	free(str);
	(void)param;
	return (0);

}

int		main(int argc, char **argv)
{
	s_data	*data;
	t_grid	*grid;

	if (argc != 2) // modify to also allow colors as input parameters
		return (ft_usage(argv[0], " <filename>"));
	grid = init_grid();
	if (!grid)
		return (ft_error("allocating space for the grid."));
	if (set_dimensions(argv[1], grid))
		return (1);

	//read file into struct
	data = init_window(400, 400, "test window");
	if (!data)
		return (0);
	int x = 0;
	while (x < 100)
	{
		int y = 0;
		while (y < 100)
		{
			mlx_pixel_put((*data).mlx,(*data).win, x, y, 0x22FFFFFF);
			y++;
		}
		x++;
	}
	mlx_key_hook((*data).win, my_key_funct, 0);
	mlx_loop((*data).mlx);

	(void)argc;
	(void)argv;
}
