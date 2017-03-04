/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:12:59 by irhett            #+#    #+#             */
/*   Updated: 2017/03/02 12:26:26 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"
#define D (*data) 

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
	{
		ft_error("Unable to allocate memory for t_data");
		return (NULL);
	}
	ft_bzero(data, sizeof(t_data));
	return (data);
}

void	del_data(t_data *data)
{
	int		i;

	if (data)
	{
		if (D.win)
		{
			i = 0;
			while (D.win[i])
				del_win(D.win[i++]);
			free(D.win);
		}
		if (D.map)
			del_map(D.map);
		if (D.frame)
			del_frame(D.frame);
		if (D.col)
		{
			i = 0;
			while (D.col[i])
				del_color(D.col[i++]);
			free(D.col);
		}
		free(D.mlx);
		ft_bzero(data, sizeof(t_data));
		free(data);
		data = NULL;
	}
	else
		ft_error("Passed NULL to del_data()");
}
