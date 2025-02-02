# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:50:15 by mrosset           #+#    #+#              #
#    Updated: 2025/02/02 13:25:52 by mrosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIRECTORY = libft
LIBFT_ARCHIVE = $(LIBFT_DIRECTORY)/libft.a

FT_PRINTF_DIRECTORY = ft_printf
FT_PRINTF_ARCHIVE = $(FT_PRINTF_DIRECTORY)/libftprintf.a

GET_NEXT_LINE_DIRECTORY = get_next_line
GET_NEXT_LINE_ARCHIVE = $(GET_NEXT_LINE_DIRECTORY)/get_next_line.a

LIBMLX_DIRECTORY = minilibx-linux
LIBMLX_ARCHIVE = $(LIBMLX_DIRECTORY)/libmlx.a

SRCS = main.c \

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -L$(LIBMLX_DIRECTORY) -lmlx -lXext -lX11 -lm -lz
INCLUDES = -I$(LIBMLX_DIRECTORY) -I.

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(GET_NEXT_LINE_ARCHIVE) $(LIBMLX_ARCHIVE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(GET_NEXT_LINE_ARCHIVE) $(LIBMLX_ARCHIVE) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_ARCHIVE):
	make -C $(LIBFT_DIRECTORY)

$(FT_PRINTF_ARCHIVE):
	make -C $(FT_PRINTF_DIRECTORY)

$(GET_NEXT_LINE_ARCHIVE):
	make -C $(GET_NEXT_LINE_DIRECTORY)

$(LIBMLX_ARCHIVE):
	make -C $(LIBMLX_DIRECTORY)

clean:
		rm -rf $(OBJS)
		make clean -C $(LIBFT_DIRECTORY)
		make clean -C $(FT_PRINTF_DIRECTORY)
		make clean -C $(GET_NEXT_LINE_DIRECTORY)
		make clean -C $(LIBMLX_DIRECTORY)
		

fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT_DIRECTORY)
		make fclean -C $(FT_PRINTF_DIRECTORY)
		make fclean -C $(GET_NEXT_LINE_DIRECTORY)
		make fclean -C $(LIBMLX_DIRECTORY)
				

re: fclean all

.PHONY: all clean fclean re