NAME = minishell

SRC = src/minishell.c parse/tokenize.c parse/delimiters.c \
	  parse/filter.c parse/checker.c parse/lst_functions.c \
	  parse/operators.c utils/libft_func.c utils/libft_func2.c \
	  parse/seperator.c parse/transformer.c parse/money_expansion.c \
	  utils/libft_func3.c parse/star_expansion.c parse/striper.c

OBJ = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror -g -fsanitize=address
# CC = cc -Wall -Wextra -Werror

t:
	@make re
	@make clean
	@clear

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean