/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:12:59 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 22:59:12 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

#define D (*data) 

void	del_data(t_data *data)
{
	if (data)
	{
		if (D.win)
			del_win_1d_arr(D.win, D.num_win);
		if (D.map)
			del_map(D.map);
		if (D.frame)
			del_frame(D.frame);
		if (D.col)
			del_col_1d_arr(D.col, D.num_col);
		free(D.mlx);
		ft_bzero(data, sizeof(t_data));
		free(data);
		data = NULL;
	}
	else
		ft_error("Passed NULL to del_data()");
}

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
