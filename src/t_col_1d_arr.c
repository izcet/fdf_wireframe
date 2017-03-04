/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_col_1d_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:09:32 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 22:02:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	del_col_1d_arr(t_col **c, int num_cols)
{
	int		i;

	if (c)
	{
		i = -1;
		while (++i < num_cols)
		{
			if (c[i])
				del_col(c[i]);
			else
				ft_error("Color Pointer in del_col_1d_arr() is NULL");
		}
		free(c);
		c = NULL;
	}
	else
		ft_error("NULL passed to del_col_1d_arr()");
}

t_col	**init_col_1d_arr(int size)
{
	t_col	**c;
	int		i;

	c = (t_col**)malloc(sizeof(t_col*) * size);
	if (!c)
	{
		ft_error("Unable to allocate memory for t_col**");
		return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		c[i] = init_col();
		if (!c[i])
		{
			del_col_1d_arr(c, i);
			return (NULL);
		}
	}
	return (c);
}

t_col	**make_col_1d_arr(t_data *data, int argc, char **argv)
{


}
