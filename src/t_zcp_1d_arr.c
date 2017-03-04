/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_zcp_1d_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:33:18 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 21:46:39 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_zcp	**init_zcp_1d_arr(int wid)
{
	t_zcp	**p;
	int		i;

	p = (t_zcp**)malloc(sizeof(t_zcp*) * wid);
	if !(p)
	{
		ft_error("Unable to allocate memory for t_zcp**");
		return (NULL);
	}
	i = -1;
	while (++i < wid)
	{
		p[i] = init_zcp();
		if (!p[i])
		{
			del_zcp_1d_arr(p, i);
			return (NULL);
		}
	}
	return (p);
}

void	del_zcp_1d_arr(t_zcp **p, int wid)
{
	int		i;

	if (p)
	{
		i = -1;
		while (++i < wid)
		{
			if (p[i])
				del_zcp(p[i]);
			else
				ft_error("Point in del_zcp_1d_arr() is NULL");
		}
		free(p);
		p = NULL;
	}
	else
		ft_error("NULL passed to del_zcp_1d_arr()");
}
