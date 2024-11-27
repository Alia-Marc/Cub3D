# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emilefournier <emilefournier@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 18:11:24 by emilefourni       #+#    #+#              #
#    Updated: 2024/11/25 18:11:52 by emilefourni      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = ./libft

INCLUDE = /include/cub3D.h

RENDERING = \

PARSING = srcs/map_parsing/map_parsing_utils.c \

# SIGNAL = srcs/signal/signal.c srcs/signal/signal_cmd.c

FLAGS = -Wall -Wextra -Werror -g3

$(NAME):    $(RENDERING) $(PARSING) srcs/main.c
			make --silent -C $(LIBFT)
			cc $(FLAGS) $(RENDERING) $(PARSING) srcs/main.c -I $(INCLUDE) $(LIBFT)/libft.a -o $(NAME)

all:    $(NAME)

bonus:  $(NAME_BONUS)

clean:
		rm -f $(NAME) $(NAME_BONUS)

fclean:    clean
		make --silent fclean -C $(LIBFT)

re:    fclean all
