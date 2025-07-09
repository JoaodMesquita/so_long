# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 10:37:04 by joapedro          #+#    #+#              #
#    Updated: 2025/07/08 14:25:44 by joapedro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRC = src/main.c src/events.c src/map_checker/parsing.c src/map_checker/check_map.c src/map_checker/check_maps_utils.c 
OBJS := $(SRC:%.c=%.o)

CC = cc
RM = rm -f

MLX_LIB = mlx-linux/libmlx_Linux.a
LIBFT = lib/lib.a

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -Imlx_linux -g

# Libraries to link with
MLX_FLAGS 	= -L ./lib/mlx -L/usr/lib/X11 -lXext -lX11

all: $(MLX_LIB) $(LIBFT) $(NAME)

# Compile MiniLibX
$(MLX_LIB):
	make -C mlx-linux

# Compile Libft
$(LIBFT):
	make -C lib

# Link final binary
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make -C lib fclean

re: fclean all

.PHONY: all clean fclean re
