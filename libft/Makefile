# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 03:33:28 by oelazzou          #+#    #+#              #
#    Updated: 2019/04/15 10:02:18 by oelazzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILE = ./ft_*.c
FLAGS = -Wall -Wextra -Werror
OBJ = ./ft_*.o
INCLUDE = ./libft.h

$(NAME): 
	gcc $(FLAGS) $(FILE) -c $(INCLUDE)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
all : $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
