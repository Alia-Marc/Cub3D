NAME = cub3D

LIBFT = ./libft

INCLUDE = /include/cub3D.h

RENDERING = \

PARSING = \

SIGNAL = srcs/signal/signal.c srcs/signal/signal_cmd.c

FLAGS = -Wall -Wextra -Werror

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
