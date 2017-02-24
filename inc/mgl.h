/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 22:42:11 by irhett            #+#    #+#             */
/*   Updated: 2017/02/24 13:31:03 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_H
#define MGL_H

#include "mlx.h"
#include "libft.h"

typedef	struct	point
{
	int			x;
	int			y;
	int			z;
	//color?
}				t_point;

typedef struct	grid
{
	int			width;
	int			length;
	t_point		**points;
}				t_grid;

typedef struct	windata
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	char		*win_title;
	t_grid		points;
}				s_data;

s_data			*init_window(int width, int height, char *title);
void			close(s_data *window);
t_grid			*read_file(char *filename);
t_grid			*init_grid(void);

#endif
