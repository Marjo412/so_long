NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS =	ft_printf.c \
		ft_print_char.c \
		ft_print_decimal.c \
		ft_print_hexa.c \
		ft_print_pointer.c \
		ft_print_string.c \
		ft_print_unsigned.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re