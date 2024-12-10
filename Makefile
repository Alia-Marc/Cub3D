# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 18:11:24 by emilefourni       #+#    #+#              #
#    Updated: 2024/12/10 16:15:04 by emfourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCLUDES = includes/cub3D.h

RENDERING = srcs/rendering/manage_window.c\

PARSING = srcs/map_parsing/map_creation.c srcs/map_parsing/map_creation_utils.c srcs/map_parsing/parse_map.c\
			srcs/map_parsing/map_creation_utils2.c\

SRCS = $(RENDERING) $(PARSING)

OBJ =	$(SRCS:.c=.o)

CC = cc -Iincludes -Ilibft -g3

all:	$(NAME)

$(NAME): $(OBJ)
	@make -C libft --no-print-directory --silent
	@make -C mlx_linux --no-print-directory --silent
	$(CC) srcs/main.c $(OBJ) -o $(NAME) libft/libft.a mlx_linux/libmlx.a -Iincludes -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

init:
	@git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
