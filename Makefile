# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 16:37:03 by mrosset           #+#    #+#              #
#    Updated: 2025/05/13 16:37:07 by mrosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIRECTORY = libs/libft
LIBFT_ARCHIVE = $(LIBFT_DIRECTORY)/libft.a

FT_PRINTF_DIRECTORY = libs/ft_printf
FT_PRINTF_ARCHIVE = $(FT_PRINTF_DIRECTORY)/libftprintf.a

GET_NEXT_LINE_DIRECTORY = libs/get_next_line
GET_NEXT_LINE_ARCHIVE = $(GET_NEXT_LINE_DIRECTORY)/get_next_line.a

LIBMLX_DIRECTORY = libs/minilibx-linux
LIBMLX_ARCHIVE = $(LIBMLX_DIRECTORY)/libmlx.a

SRCS =	main.c \
		game.c \
		maps.c \
		move.c \
		maps_checks.c \
		maps_utils.c \
		maps_path.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -L$(LIBMLX_DIRECTORY) -lmlx -lXext -lX11 -lm -lz
INCLUDES = -I$(LIBMLX_DIRECTORY) -I$(LIBFT_DIRECTORY) -I$(GET_NEXT_LINE_DIRECTORY) -I$(FT_PRINTF_DIRECTORY) -I.

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(GET_NEXT_LINE_ARCHIVE) $(LIBMLX_ARCHIVE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(GET_NEXT_LINE_ARCHIVE) $(LIBMLX_ARCHIVE) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_DIRECTORY)

$(FT_PRINTF_ARCHIVE):
	$(MAKE) -C $(FT_PRINTF_DIRECTORY)

$(GET_NEXT_LINE_ARCHIVE):
	$(MAKE) -C $(GET_NEXT_LINE_DIRECTORY)

$(LIBMLX_ARCHIVE):
	$(MAKE) -C $(LIBMLX_DIRECTORY)

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