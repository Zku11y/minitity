NAME = ex_b9

SRC = main.c start.c

OBJ = $(SRC:.c=.o)

CC = cc #-Wall -Wextra -Werror

all:$(NAME)

t: all clean
	./ex_b9

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
