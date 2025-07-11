# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 10:12:33 by joapedro          #+#    #+#              #
#    Updated: 2025/07/11 15:40:18 by joapedro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a

SRC = $(addsuffix .c, ft_strstr ft_putchar ft_putstr ft_printf ft_putnbr ft_unsigned_putnbr ft_puthexa ft_puthexa_big ft_pointer get_next_line_bonus get_next_line_utils_bonus ft_strchr ft_strrchr ft_strlen ft_strncmp ft_strcmp)

OBJS := $(SRC:%.c=%.o)

CC = cc

RM = rm -f

CCFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
