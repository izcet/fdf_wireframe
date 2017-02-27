/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 22:42:11 by irhett            #+#    #+#             */
/*   Updated: 2017/02/26 18:58:22 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_H
#define MGL_H

#include "mlx.h"
#include "libft.h"
#include <fcntl.h>

typedef struct			xypoint
{
	int					x;
	int					y;
}						t_xy;

typedef	struct			color
{
	unsigned char		a;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

typedef	struct			zcpoint
{
	int					z;
	t_color				*color;
}						t_zc;

typedef struct			grid
{
	int					z_high; // highest height of a point
	int					z_low; // lowest low point
	int					width; // number of points in a row
	int					length; // number of points in a col
	t_zc				**p; // array of points' z values and colors
}						t_grid;

// according to standard there are 3 vectors I need to store
// world which is grid points relative to each other
// local which is the window
// and the third which is ????

typedef struct			data
{
	void				*mlx; // pointer for graphics engine
	void				*win; //pointer for window
	int					win_width; // width of window, in pixels
	int					win_height; // height of window, in pixels
	char				*win_title;
	t_grid				*grid; // grid of points
	// I still need to handle the 3d of the points to the 2d of the window
	// add a view reference maybe?
	// double center x
	// double center y
	// double range (distance from center relative to original dimensions)
	//
}						t_data;

t_data					*init_window(int width, int height, char *title);
void					close_win(t_data *data);
//t_grid					*read_file(char *filename);
t_grid					*init_grid(void);

/*
 * checks for errors in the file and returns true if any are found
 * otherwise it sets the grid.width and grid.length values	
 */
int						set_dimensions(char *file, t_grid *grid);
int						is_valid_color(char *str);

void					read_file_into_grid(char *file, t_grid *grid);
int						grid_error(t_grid *grid, char *msg);
int						str_to_color(char *str, t_zc point);

unsigned int			set_color_from_chars(char a, char r, char g, char b);
unsigned int			set_color(t_color *c);

int						key_pressed(int keycode, void *param);

void					print_row(int row, t_grid *grid);
#endif
