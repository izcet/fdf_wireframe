/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 22:42:11 by irhett            #+#    #+#             */
/*   Updated: 2017/02/28 11:27:36 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGL_H
# define MGL_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>

# define WINDOW_SIZE	800
# define COLOR_MAX		0x00FF0000
# define COLOR_MID		0x0000FF00
# define COLOR_MIN		0x000000FF

typedef	struct			s_color
{
	unsigned char		a;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

typedef struct			s_xy_point
{
	int					x;
	int					y;
	t_color				*color;
}						t_xy;

typedef	struct			s_zc_point
{
	int					z;
	t_color				*color;
}						t_zc;

typedef struct			s_float_point
{
	float				x;
	float				y;
	float				z;
}						t_fp;

typedef struct			s_grid
{
	float				x_axis_rot;
	float				y_axis_rot;
	float				z_axis_rot;

	int					z_max;
	int					z_min;
	t_color				**cols;
	int					num_cols;

	int					width;
	int					length;
	t_zc				**p;
}						t_grid;

typedef struct			s_window
{
	float				scale;
	float				z_axis_rot;
	float				x_axis_rot;
	float				y_axis_rot;
	char				*title;
	void				*ptr;
}						t_win;

typedef struct			s_data
{

	void				*mlx;
	t_win				*win;
	t_grid				*grid;
	// I still need to handle the 3d of the points to the 2d of the window
	// add a view reference maybe?
	// double center x
	// double center y
	// double range (distance from center relative to original dimensions)
	//
}						t_data;

// according to standard there are 3 vectors I need to store
// world which is grid points relative to each other
// local which is the window
// and the third which is ????

t_data					*init_data(char *title, t_grid *grid, t_color **color);
t_win					*init_window(char *title, void *mlx);
t_grid					*init_grid(void);

int						is_valid_file(char *file, t_grid *grid);
void					read_file_into_grid(char *file, t_grid *grid);

int						key_pressed(int keycode, void *ptr);

int						is_valid_color(char *str);
t_color					*str_to_color(char *str);
unsigned int			set_color_from_chars(char a, char r, char g, char b);
unsigned int			set_color(t_color *c);
unsigned int			gradient_color(t_color *a, t_color *b, int n, int val);

void					close_win(t_data *data);
void					free_win(t_win *win);
void					free_grid(t_grid *grid);
int						grid_error(t_grid *grid, char *msg);

void					print_grid(t_grid *grid);
void					print_row(int row, t_grid *grid);

void					draw_line(t_xy *a, t_xy *b, t_data *d);

t_color					**read_colors(int argc, char **argv, t_grid *grid);
t_color					*set_color_from_int(unsigned int c);
void					set_point_colors(t_grid *grid);
void					draw_grid(t_grid *grid, t_data *data, int row, int col);
void					set_offset(t_grid *grid, t_data *data);
#endif
