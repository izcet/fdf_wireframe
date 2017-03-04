/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_zcp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:19:37 by irhett            #+#    #+#             */
/*   Updated: 2017/03/02 13:20:21 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_zcp	*init_zcp(void)
{
	t_zcp	*p;

	p = (t_zcp*)malloc(sizeof(t_zcp));
	if (!p)
	{
		ft_error("Unable to allocate memory for t_zcp");
		return (NULL);
	}
	ft_bzero(p, sizeof(t_zcp));
	return (p);
}

void	del_zcp(t_zcp *p)
{
	if (p)
	{
		if ((*p).c)
			del_color((*p).c);
		ft_bzero(p, sizeof(t_zcp));
		free(p);
		p = NULL;
	}
	else
		ft_error("Passed NULL to del_zcp()");
}
