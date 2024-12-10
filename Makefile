# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 18:11:24 by emilefourni       #+#    #+#              #
#    Updated: 2024/12/10 14:10:27 by emfourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = ./libft
MLX = ./minilibx-linux

INCLUDE = include/cub3D.h

RENDERING = \

PARSING = srcs/map_parsing/map_creation.c srcs/map_parsing/map_creation_utils.c srcs/map_parsing/parse_map.c\
			srcs/map_parsing/map_creation_utils2.c\

FLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -L$(MLX) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

$(NAME): $(RENDERING) $(PARSING) srcs/main.c
			make --silent -C $(LIBFT)
			make --silent -C $(MLX)
			cc $(FLAGS) $(RENDERING) $(PARSING) srcs/main.c -I $(INCLUDE) $(LIBFT)/libft.a $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
		rm -f $(NAME) $(NAME_BONUS)
		make --silent clean -C $(LIBFT)
		make --silent clean -C $(MLX)

fclean: clean
		make --silent fclean -C $(LIBFT)
		rm -f $(NAME)

re: fclean all


