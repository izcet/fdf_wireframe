/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 22:42:11 by irhett            #+#    #+#             */
/*   Updated: 2017/03/03 22:57:17 by irhett           ###   ########.fr       */
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
}						t_col;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_xyp;

typedef	struct			s_point
{
	int					z;
	t_col				*c;
}						t_zcp;

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
	t_col				*c;
}						t_xyzcp;

typedef struct			s_grid
{
	t_zcp				**p;
}						t_map;

typedef struct			s_grid
{
	t_xyzcp				**p;
	t_xyzcp				*pos;
	t_xyzcp				*ang;
}						t_frame;

typedef struct			s_window
{
	void				*ptr;
	//function pointers // null terminated array?
	t_xyzcp				*pos;
	t_xyzcp				*ang;
	unsigned int		range; //distance between points in rendering
	t_data				*root;
	// what other variables do I need to render a window?
}						t_win;

typedef struct			s_data
{
	int					wid; // for the point arrays
	int					len; // for the point arrays
	int					z_min;
	int					z_max;
	int					num_win;
	t_win				**win; //array[num_win] of windows
	t_map				*map;
	t_frame				*frame;
	int					num_col;
	t_col				**col; // array[num_col] of colors // [0] is low
	void				*mlx;
	// what other structures and data do I want to pass around the whole fdf?

}						t_data;

t_col					*init_col(void);
t_xyp					*init_xyp(void);
t_zcp					*init_zcp(void);
t_xyzcp					*init_xyzcp(void);
t_map					*init_map(void);
t_frame					*init_frame(void);
t_win					*init_win(void);
t_data					*init_data(void);
t_zcp					**init_zcp_1d_arr(int wid);
t_zcp					***init_zcp_2d_arr(int len, int wid);
t_xyzcp					**init_xyzcp_1d_arr(int wid);
t_xyzcp					***init_xyzcp_2d_arr(int len, int wid);
t_col					**init_col_1d_arr(int size);

void					del_col(t_col *c);
void					del_xyp(t_xyp *p);
void					del_zcp(t_zcp *p);
void					del_xyzcp(t_xyzcp *p);
void					del_map(t_map *grid);
void					del_frame(t_frame *grid, int p_rows, int p_cols);
void					del_win(t_win *win, void *mlx); // see file
void					del_data(t_data *data); // see file
void					del_zcp_1d_arr(t_zcp **p, int wid);
void					del_zcp_2d_arr(t_zcp ***p, int len, int wid);
void					del_xyzcp_1d_arr(t_xyzcp **p, int wid);
void					del_xyzcp_2d_arr(t_xyzcp ***p, int len, int wid);
void					del_col_1d_arr(t_col **c, int size);

t_col					*make_col_from_chars(char a, char r, char g, char b);
t_col					*make_col_from_int(unsigned int num); // 0x00AA11FF
t_col					*make_col_from_str(char *str); // "0x00AAFF"
t_col					**make_col_1d_arr(t_data *data, int argc, char **argv)
unsigned int			get_int_from_chars(char a, char r, char g, char b);
unsigned int			get_int_from_col(t_col *c);
int						is_valid_color(char *str);

t_xyp					*make_xyp(int x, int y);
t_zcp					*make_zcp(int z, t_col *c);

// returns (wid, len) t_xyp, or NULL for invalid file
t_xyp					*parse_file(char *file);

void					set_z_range(t_data *data);
void					set_data_xy(t_data *data, t_xyp *p);
void					set_point_colors(t_data *data, int argc, char **argv);
int						populate_map(t_data *data, char *file);

t_col					*get_color_from_range(t_data *data, int row, int col);
// recode				this ^^^







unsigned int			gradient_color(t_color *a, t_color *b, int n, int val);


/*typedef struct			s_grid
{
	int					offset;


	t_zc				**p;
	int					p_wid;
	int					p_len;
	
	int					z_max;
	int					z_min;
	
	t_color				**c;
	int					c_num;
}						t_grid;

typedef struct			s_window
{
	float				scale; // distance between points
	int					center_x; // center of grid relative to (0, 0)
	int					center_y;
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
}*/						t_data;

// according to standard there are 3 vectors I need to store
// world which is grid points relative to each other
// local which is the window
// and the third which is ????
void					read_file_into_grid(char *file, t_grid *grid);

int						key_pressed(int keycode, void *ptr);
int						mouse_pressed(int button, int x, int y, void *ptr);

void					close_win(t_data *data);
void					free_win(t_win *win);
void					free_grid(t_grid *grid);
int						grid_error(t_grid *grid, char *msg);

void					print_grid(t_grid *grid);
void					print_row(int row, t_grid *grid);

void					draw_line(t_xy *a, t_xy *b, t_data *d);

t_color					**read_colors(int argc, char **argv, t_grid *grid);
void					set_point_colors(t_grid *grid);
void					draw_grid(t_grid *grid, t_data *data, int row, int col);
void					set_offset(t_grid *grid, t_data *data);
#endif
