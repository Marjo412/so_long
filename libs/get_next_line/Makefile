# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 10:56:22 by mrosset           #+#    #+#              #
#    Updated: 2025/02/09 13:43:20 by mrosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIRECTORY = ../libft
LIBFT_ARCHIVE = $(LIBFT_DIRECTORY)/libft.a

SRCS =  get_next_line.c \
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE)
	ar rcs $(NAME) $(OBJS)

all: $(NAME) $(LIBFT_ARCHIVE)

$(LIBFT_ARCHIVE):
	make -C $(LIBFT_DIRECTORY)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re