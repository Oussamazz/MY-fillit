# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 21:40:48 by oelazzou          #+#    #+#              #
#    Updated: 2019/05/24 22:43:14 by oelazzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c validate.c my_read.c map.c error.c solve.c print.c
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft re
	$(CC) $(FLAGS) $(OBJ) ./libft/libft.a  -o $(NAME)
$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)
clean:
	make -C libft clean
	rm -f $(NAME)
fclean:
	make -C libft fclean
	rm -f $(NAME) $(OBJ)
re: fclean all
