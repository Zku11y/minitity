NAME = minishell

SRC = src/minishell.c parse/tokenize.c parse/delimiters.c \
	  parse/filter.c parse/lst_functions.c parse/operators.c \
	  utils/libft_func.c

OBJ = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: clean