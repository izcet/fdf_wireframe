# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 20:58:56 by irhett            #+#    #+#              #
#    Updated: 2017/09/11 15:04:03 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
MLX_DIR		=	mlx
MLX			=	$(MLX_DIR)/libmlx.a

LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a
LIBFT_INC	=	includes
LIB			=	$(LIBFT_DIR)/$(LIBFT_LIB)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra #-fsanitize=address 
GFLAGS		=	-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit 
FLAGS		=	$(CFLAGS) $(GFLAGS)

SRC_DIR		= 	src

SRC_FILE	=	main.c get_col_from_range.c gradient_col.c parse_file.c\
				make_col_from_int.c make_col_from_str.c is_valid_color.c \
				get_int_from_chars.c get_int_from_col.c t_col.c \
				set_point_cols.c t_zcp.c t_zcp_1d_arr.c t_zcp_2d_arr.c \
				t_data.c t_col_1d_arr.c t_win.c t_frame.c t_win_1d_arr.c \
				t_xyzcp.c t_xyzcp_1d_arr.c t_xyzcp_2d_arr.c set_z_range.c \
				populate_map.c set_data_xy.c t_xyp.c print_data_map.c \
				print_data_row.c rotate_point_by_matrix.c set_xyzcp.c \
				rotate_point_around_origin.c rotate_point_around_point.c \
				make_xyzcp_from_zcp.c set_win.c rotate_grid_x.c \
				rotate_grid_y.c rotate_grid_z.c set_window_hooks.c \
				key_pressed.c mouse_pressed.c expose_hook.c loop_hook.c \
				draw_grid.c draw_line.c print_keys.c

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

INC_DIR		=	-I inc -I $(MLX_DIR) -I $(LIBFT_DIR)/$(LIBFT_INC)

.PHONY: all clean fclean re libft mlx

all: $(MLX) $(LIB) $(NAME)

$(NAME): $(SRCS) | $(OBJS) 
	$(CC) $(FLAGS) $(LIB) $(OBJS) $(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -c $^ $(CFLAGS) $(INC_DIR) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@cd $(LIBFT_DIR) && make clean
	@cd $(MLX_DIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT_DIR) && make fclean

re:	fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
