NAME = minishell

SRC = src/minishell.c parse/tokenize.c

OBJ = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lreadline

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: clean