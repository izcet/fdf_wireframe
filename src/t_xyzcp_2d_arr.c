/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_xyzcp_2d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:59:24 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 21:46:41 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_xyzcp		***init_xzycp_2d_arr(int len, int wid)
{
	t_xyzcp	***p;
	int		i;

	p = (t_xyzcp***)malloc(sizeof(t_xyzcp**) * len);
	if (!p)
	{
		ft_error("Unable to allocate memory for t_xyzcp***");
		return (NULL);
	}
	i = -1;
	while (++i < len)
	{
		p[i] = init_xyzcp_1d_arr(wid);
		if (!p[i])
		{
			del_xyzcp_2d_arr(p, i, wid);
			return (NULL);
		}
	}
	return (p);
}


void	del_xyzcp_2d_arr(t_xyzcp ***p, int len, int wid)
{
	int		i;

	if (p)
	{
		i = -1;
		while (++i < len)
		{
			if (p[i])
				del_xyzcp_1d_arr(p[i], wid);
			else
				ft_error("Row pointer in del_xyzcp_2d_arr() is NULL");
		}
		free(p);
		p = NULL;
	}
	else
		ft_error("Passed NULL to del_xyzcp_2d_arr()");
}
