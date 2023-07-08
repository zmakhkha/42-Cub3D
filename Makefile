# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 19:01:56 by zmakhkha          #+#    #+#              #
#    Updated: 2023/07/08 21:38:15 by zmakhkha         ###   ########.fr        #
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
HEADERS = header.h


# Source files
SRC_MN =	src/main.c \
			src/ft_map.c \
			src/ft_mlx.c \
			src/ft_utils.c \
			src/ft_player.c \
			
		 
#Objects
SRC = $(SRC_MN) 
OBJ = $(addprefix objs/, $(SRC:.c=.o))


all: $(NAME)


$(NAME) : $(OBJ) $(HEADERS) $(LBFT)
	@$(CC) $(OBJ) $(LBFT) $(MLBX) -o $(NAME)
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