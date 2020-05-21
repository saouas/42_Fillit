# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratin <ratin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:46:26 by ratin             #+#    #+#              #
#    Updated: 2018/11/28 15:40:36 by ratin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = src

SRC_NAME =	read_file.c	\
			fill_struct.c \
			check_input_file.c \
			place_tetriminos.c \
			create_map.c \
			get_uper_left.c \
			utility.c \
			main.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJECT_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC = -Iinclude
INC_PATH = includes/

LDFLAGS = -Llibft
LDLIBS = -lft

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJECT_NAME)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJECT_NAME) -o $@

%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJECT_NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/$(NAME).h
	norminette libft/includes/libft.h