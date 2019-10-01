# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 03:33:28 by oelazzou          #+#    #+#              #
#    Updated: 2019/05/26 21:17:33 by oelazzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILE = ./ft_*.c
FLAGS = -Wall -Wextra -Werror
OBJ = ./ft_*.o

$(NAME): 
	gcc $(FLAGS) $(FILE) -c 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
all : $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
