# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 19:01:56 by zmakhkha          #+#    #+#              #
#    Updated: 2023/08/22 17:29:07 by edraidry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = cub3D
NAME_B = cub3D_bonus
LBFT = libft/libft.a
LIBFT_DIR = libft
#CFLAGS = -Wall -Werror -Wextra
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
			Madnatory/parsing/split_utils.c \
			Madnatory/parsing/pars_utils.c \
			Madnatory/parsing/main__parsing.c \

# Source files
SRC_MN =	Madnatory/src/ft_map.c \
			Madnatory/src/ft_utils.c \
			Madnatory/src/ft_player.c \
			Madnatory/src/mlx/ft_init.c \
			Madnatory/src/mlx/ft_mlx.c \
			Madnatory/src/mlx/ft_shapes.c \
			Madnatory/src/mlx/ft_hooks.c \
			Madnatory/src/ft_rays.c \
			Madnatory/src/ft__rays.c \
			Madnatory/src/ft___rays.c \
			Madnatory/src/ft_walls.c \
			Madnatory/src/ft__walls.c \

SRC_BN = 	Bonus/src/ft_utils_bonus.c


SRC_MAIN =	Madnatory/src/main.c
SRC_BONUS =	Bonus/src/main_bonus.c

#Objects
SRC_M = $(SRC_MN) $(PARSING) $(SRC_MAIN)
OBJ_M = $(addprefix objs/, $(SRC_M:.c=.o))

SRC_B = $(SRC_MN) $(SRC_BN) $(PARSING) $(SRC_BONUS)
OBJ_B = $(addprefix objs/, $(SRC_B:.c=.o))


all: $(NAME)


$(NAME) : $(OBJ_M) $(HEADERS) $(LBFT)
	@$(CC) $(OBJ_M) $(LBFT) $(MLBX) -o $(NAME)
	@echo "$(NAME): $(GREEN)Successfully made. ✅$(RESET)"

LIB_DIR:
	@make -C $(LIBFT_DIR)

objs/%.o: %.c  $(HEADERS)  Makefile | LIB_DIR
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Imlx  -c $< -o $@


clean:
	@rm -rf  objs $(OBJ_M) $(OBJ_B)
	@make clean -C $(LIBFT_DIR)
	@echo "$(NAME): $(RED)Objects removed successfully 🗑️$(RESET)"

fclean: clean
	@rm -f $(NAME) $(NAME_B)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(NAME): $(RED)Executable removed successfully 🗑️$(RESET)"

re: fclean all
bonus : $(OBJ_B) $(HEADERS) $(LBFT)
	@$(CC) $(OBJ_B) $(LBFT) $(MLBX) -o $(NAME_B)
	@echo "$(NAME): $(GREEN)Successfully made. ✅$(RESET)"
.PHONY: all re fclean clean