# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 20:58:56 by irhett            #+#    #+#              #
#    Updated: 2017/02/27 20:44:30 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
MLX_DIR		=	mlx/
MLX			=	$(MLX_DIR)libmlx.a

LIBFT_DIR	=	libft/
LIBFT_LIB	=	libft.a
LIBFT_INC	=	includes
LIB			=	$(LIBFT_DIR)$(LIBFT_LIB)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra 
GFLAGS		=	-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit 
FLAGS		=	$(CFLAGS) $(GFLAGS)

SRC_DIR		= 	src
SRC_FILE	=	close_win.c free_grid.c grid_error.c init_data.c init_grid.c \
				init_window.c is_valid_color.c key_pressed.c main.c \
				print_row.c print_grid.c read_file_into_grid.c set_color.c \
				is_valid_file.c str_to_color.c free_win.c draw_line.c \
				gradient_color.c read_colors.c set_color_from_int.c \
				set_point_colors.c draw_grid.c set_offset.c

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

INC_DIR		=	-I inc -I $(MLX_DIR) -I $(LIBFT_DIR)$(LIBFT_INC)

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
#	@cd $(MLX_DIR) && make fclean

re:	fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
