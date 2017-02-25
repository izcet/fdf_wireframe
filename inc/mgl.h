/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 22:42:11 by irhett            #+#    #+#             */
/*   Updated: 2017/02/25 01:13:15 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_H
#define MGL_H

#include "mlx.h"
#include "libft.h"
#include <fcntl.h>

typedef	struct			color
{
	unsigned char		a;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

typedef	struct			point
{
	int					x;
	int					y;
	int					z;
	t_color				*color;
}						t_point;

typedef struct			grid
{
	int					width;
	int					length;
	t_point				**points;
}						t_grid;

typedef struct			windata
{
	void				*mlx;
	void				*win;
	int					win_width;
	int					win_height;
	char				*win_title;
	t_grid				*points;
}						s_data;

s_data					*init_window(int width, int height, char *title);
void					close_win(s_data *window);
t_grid					*read_file(char *filename);
t_grid					*init_grid(void);

/*
 * checks for errors in the file and returns true if any are found
 * otherwise it sets the grid.width and grid.length values	
 */
int						set_dimensions(char *file, t_grid *grid);
int						is_valid_color(char *str);

void					read_grid(char *file, t_grid *grid);
int						grid_error(t_grid *grid, char *msg);
int						set_color(char *str, t_point point);

#endif
