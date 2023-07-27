# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 19:01:56 by zmakhkha          #+#    #+#              #
#    Updated: 2023/07/27 08:30:41 by zmakhkha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = cub3D
LBFT = libft/libft.a
LIBFT_DIR = libft
CFLAGS = -g #-Wall -Werror -Wextra -g 
MLBX = -lmlx -framework OpenGL -framework AppKit
HEADERS =	headers/header.h\
			headers/structs.h \
			headers/cub3d.h

PARSING =	parsing/check_f_and_c.c parsing/main_parsing.c \
			parsing/file_content.c  parsing/read_file.c \
			parsing/get_next_line/get_next_line.c \
			parsing/get_next_line/get_next_line_utils.c

# Source files
SRC_MN =	src/main.c	src/ft_map.c	src/ft_utils.c	src/ft_player.c \
			src/mlx/ft_init.c			src/mlx/ft_mlx.c	src/mlx/ft_shapes.c\
			src/mlx/ft_hooks.c			src/ft_rays.c
			
		 
#Objects
SRC = $(SRC_MN) $(PARSING)
OBJ = $(addprefix objs/, $(SRC:.c=.o))


all: $(NAME)


$(NAME) : $(OBJ) $(HEADERS) $(LBFT)
	@$(CC) $(OBJ) $(LBFT) $(MLBX) -o $(NAME) -fsanitize=address
	@echo "$(NAME): $(GREEN)Successfully made. ✅$(RESET)"

LIB_DIR:
	@make -C $(LIBFT_DIR)

objs/%.o: %.c  $(HEADERS)  Makefile | LIB_DIR
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Imlx  -c $< -o $@


clean:
	@rm -rf  objs $(OBJ)
	@echo "$(NAME): $(RED)Objects removed successfully 🗑️$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)Executable removed successfully 🗑️$(RESET)"

re: fclean all

.PHONY: all re fclean clean