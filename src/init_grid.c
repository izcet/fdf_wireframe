/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:19:04 by irhett            #+#    #+#             */
/*   Updated: 2017/02/26 16:06:23 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

t_grid	*init_grid(void)
{
	t_grid	*new;

	new = (t_grid*)malloc(sizeof(t_grid));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(*new));
	return (new);
}
