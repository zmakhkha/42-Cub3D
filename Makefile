# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 19:01:56 by zmakhkha          #+#    #+#              #
#    Updated: 2023/08/05 08:22:29 by zmakhkha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = cub3D
LBFT = libft/libft.a
LIBFT_DIR = libft
CFLAGS = -g -Wall -Werror -Wextra -g 
MLBX = -lmlx -framework OpenGL -framework AppKit

HEADERS =	Madnatory/headers/header.h\
			Madnatory/headers/structs.h \
			Madnatory/headers/cub3d.h

PARSING =	Madnatory/parsing/check_f_and_c.c \
			Madnatory/parsing/main_parsing.c \
			Madnatory/parsing/file_content.c  \
			Madnatory/parsing/read_file.c \
			Madnatory/parsing/get_next_line/get_next_line.c \
			Madnatory/parsing/get_next_line/get_next_line_utils.c \

# Source files
SRC_MN =	Madnatory/src/main.c \
			Madnatory/src/ft_map.c \
			Madnatory/src/ft_utils.c \
			Madnatory/src/ft_player.c \
			Madnatory/src/mlx/ft_init.c \
			Madnatory/src/mlx/ft_mlx.c \
			Madnatory/src/mlx/ft_shapes.c \
			Madnatory/src/mlx/ft_hooks.c \
			Madnatory/src/ft_rays.c \

#Objects
SRC_M = $(SRC_MN) $(PARSING)
OBJ_M = $(addprefix objs/, $(SRC_M:.c=.o))


all: $(NAME)


$(NAME) : $(OBJ_M) $(HEADERS) $(LBFT)
	@$(CC) $(OBJ_M) $(LBFT) $(MLBX) -o $(NAME) -fsanitize=address
	@echo "$(NAME): $(GREEN)Successfully made. ✅$(RESET)"

LIB_DIR:
	@make -C $(LIBFT_DIR)

objs/%.o: %.c  $(HEADERS)  Makefile | LIB_DIR
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Imlx  -c $< -o $@


clean:
	@rm -rf  objs $(OBJ_M)
	@echo "$(NAME): $(RED)Objects removed successfully 🗑️$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)Executable removed successfully 🗑️$(RESET)"

re: fclean all

.PHONY: all re fclean clean