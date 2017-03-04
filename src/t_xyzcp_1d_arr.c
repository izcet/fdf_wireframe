/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_xyzcp_1d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:27:56 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 21:47:03 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_xyzcp		**init_xyzcp_1d_arr(int wid)
{
	t_xyzcp	**p;
	int		i;

	p = (t_xyzcp**)malloc(sizeof(t_xyzcp*) * wid);
	if (!p)
	{
		ft_error("Unable to allocate memory for t_xyzcp**");
		return (NULL);
	}
	i = -1;
	while (++i < wid)
	{
		p[i] = init_xyzcp();
		if (!p[i])
		{
			del_xyzcp_1d_arr(p, i);
			return (NULL);
		}
	}
	return (p);
}

void		del_xyzcp_1d_arr(t_xyzcp **p, int wid)
{
	int		i;

	if (p)
	{
		i = -1;
		while (++i < wid)
		{
			if (p[i])
				del_xyzcp(p[i]);
			else
				ft_error("Point in del_xyzcp_1d_arr() is NULL");
		}
		free(p);
		p = NULL;
	}
	else
		ft_error("Passed NULL to del_xyzcp_2d_arr()");
}
