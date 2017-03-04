/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_zcp_2d_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:00:56 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 22:01:49 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

void	del_zcp_2d_arr(t_zcp ***p, int len, int wid)
{
	int		i;

	if (p)
	{
		i = -1;
		while (++i < len)
		{
			if (p[i])
				del_zcp_1d_arr(p[i], wid);
			else
				ft_error("Row pointer in del_xyzcp_2d_arr() is NULL");
		}
		free(p);
		p = NULL;
	}
	else
		ft_error("Passed NULL to del_xyzcp_2d_arr()");
}

t_zcp	***init_zcp_2d_arr(int len, int wid)
{
	t_zcp	***p;
	int		i;

	p = (t_zcp***)malloc(sizeof(t_zcp**) * len);
	if (!p)
	{
		ft_error("Unable to allocate memory for init_zcp_2d_arr()");
		return (NULL);
	}
	i = -1;
	while (++i < len)
	{
		p[i] = init_zcp_1d_arr(wid);
		if (!p[i])
		{
			del_zcp_2d_arr(p, i, wid);
			return (NULL);
		}
	}
	return (p);
}
