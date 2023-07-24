# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 12:24:46 by edraidry          #+#    #+#              #
#    Updated: 2023/07/23 19:00:19 by edraidry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = main.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c read_file.c file_content.c \
		libft/ft_strdup.c check_f_and_c.c

HEADER = cub3d.h

CC = cc

CFLAGS =  -g -fsanitize=address #-Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)  fclean

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all


#run:
#	@echo "\033c"
#	@./cub3d map.cub

.PHONY: all clean fclean re