# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbetz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 19:46:58 by bbetz             #+#    #+#              #
#    Updated: 2016/06/06 23:44:30 by bbetz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAG = -Wall -Werror -Wextra

EXTRA_FLAGS = -lmlx -framework OpenGL -framework AppKit

INC = 	./include/						\
		

SRC =	./sources/main.c 				\
		./sources/divers.c 				\
		./sources/draw_fract.c 			\
		./sources/key_events.c 			\
		./sources/mandelbrot.c			\
		./sources/write_pixel.c			\
		./sources/julia.c 				\
		./sources/mouse_events.c 		\
		./sources/fractale3.c			\

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC)  -I $(INC) $(LIB) $(EXTRA_FLAGS) $(SRC) -o $(NAME)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
