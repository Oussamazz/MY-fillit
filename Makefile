# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 21:40:48 by oelazzou          #+#    #+#              #
#    Updated: 2019/05/23 21:55:24 by oelazzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c validate.c my_read.c map.c error.c solve.c
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) ./libft/libft.a  -o $(NAME)
$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME) $(OBJ)
re: fclean all
