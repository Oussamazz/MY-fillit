NAME = test
SRC = main.c validate.c my_read.c map.c error.c solve.c
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) libft.a  -o $(NAME)
$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME) $(OBJ)
re: fclean all
