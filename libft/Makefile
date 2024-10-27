NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isascii.c ft_isalnum.c ft_calloc.c \
	ft_isalpha.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_tolower.c ft_toupper.c ft_memcmp.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c get_next_line.c ft_printf.c ft_printf_output.c \
	ft_strcat.c ft_free_tab.c ft_strcmp.c ft_strlen2.c ft_atol.c \
	ft_lenint.c ft_natol.c ft_check_charset.c ft_strjoin_freed.c \
	ft_random.c fdprintf/ft_fdprintf_output.c fdprintf/ft_fdprintf.c \
	ft_isspace.c ft_dup_tab.c ft_strlen_until_char.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.c.o:
	cc $(FLAGS) -I libft/libft.h -c $< -o $(<:.c=.o)

$(NAME):    $(OBJ)
			ar -rc -o $(NAME) $(OBJ)

all:    $(NAME)

clean:
		rm -f $(OBJ)

fclean:    clean
		rm -f $(NAME)

re:    fclean all