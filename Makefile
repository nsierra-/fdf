# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/02 08:22:33 by nsierra-          #+#    #+#              #
#    Updated: 2014/05/19 08:55:18 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

INC_FILES	=	fdf.h

SRC_FILES	=	main.c \
				load_map.c \
				render.c \
				handle_key_event.c \
				handle_mouse_event.c \
				free_map.c

FTLST_DIR	=	./ftlst
LIBFT_DIR	=	./libft
MLX_DIR		=	minilibx

SRC			=	$(addprefix src/, $(SRC_FILES))
INC			=	$(addprefix inc/, $(INC_FILES))
OBJ			=	$(SRC:.c=.o)

CC			=	gcc
MAKE		=	make

CFLAGS		=	-Wall -Wextra -Werror -pedantic
IFLAGS		=	-I./inc/ -I$(LIBFT_DIR) -I$(FTLST_DIR) -I$(MLX_DIR)
LDFLAGS		=	-L$(LIBFT_DIR) -lft -L$(FTLST_DIR) -lftlst -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

$(NAME):		subm $(INC) $(OBJ)
				$(MAKE) -C ftlst/
				$(MAKE) -C libft/
				$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $@

all:			$(NAME)

%.o:			%.c
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
				$(MAKE) -C libft/ clean
				$(MAKE) -C ftlst/ clean
				rm -rf $(OBJ)

fclean:			clean
				$(MAKE) -C libft/ fclean
				$(MAKE) -C ftlst/ fclean
				rm -f $(NAME)

test:			all
				./$(NAME) maps/01.fdf

re:				fclean all

subm:
				test -d "./ftlst" || git submodule add -b 42 https://github.com/nsierra-/ftlst.git ftlst
				test -d "./libft" || git submodule add -b master https://github.com/nsierra-/libft.git libft
				git submodule update --init --remote --recursive

.PHONY:
