# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malia <malia@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 18:11:24 by emilefourni       #+#    #+#              #
#    Updated: 2025/04/17 20:07:51 by malia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

INCLUDES = includes/cub3D.h

RENDERING = srcs/rendering/manage_window.c srcs/rendering/init.c srcs/rendering/dda.c \
			srcs/rendering/draw_dda.c srcs/rendering/exit.c srcs/rendering/init_utils.c \

PARSING = srcs/map_parsing/map_creation.c srcs/map_parsing/map_creation_utils.c srcs/map_parsing/parse_map.c \
			srcs/map_parsing/map_creation_utils2.c srcs/map_parsing/map_creation_utils3.c\

EVENTS = srcs/events/hooks.c srcs/events/events.c srcs/events/player_events.c \

SRCS = $(RENDERING) $(PARSING) $(EVENTS)

RENDERING_BONUS = srcs/rendering/manage_window.c srcs/rendering/init.c srcs/rendering/dda.c \
			srcs/rendering/draw_dda.c srcs/rendering/exit.c srcs/rendering/init_utils.c \

PARSING_BONUS = srcs/map_parsing/map_creation.c srcs/map_parsing/map_creation_utils.c srcs/map_parsing/parse_map.c \
			srcs/map_parsing/map_creation_utils2.c srcs/map_parsing/map_creation_utils3.c\

EVENTS_BONUS = srcs/events/hooks_bonus.c srcs/events/events.c srcs/events/player_events.c \

SRCS_BONUS = $(RENDERING_BONUS) $(PARSING_BONUS) $(EVENTS_BONUS)

CC = cc -Iincludes -Ilibft -g3

all:	$(NAME)

$(NAME): $(SRCS) srcs/main.c
	@make -C libft --no-print-directory --silent
	@make -C mlx_linux --no-print-directory --silent
	$(CC) srcs/main.c $(SRCS) -o $(NAME) libft/libft.a mlx_linux/libmlx.a -Iincludes -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(NAME_BONUS): $(SRCS_BONUS) srcs/main.c
	@make -C libft --no-print-directory --silent
	@make -C mlx_linux --no-print-directory --silent
	$(CC) srcs/main.c $(SRCS_BONUS) -o $(NAME_BONUS) libft/libft.a mlx_linux/libmlx.a -Iincludes -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz


clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

bonus:	$(NAME_BONUS)

init:
	@git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
