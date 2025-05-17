


NAME = run

LIB = libft/*.c

SRC = main.c\
	m_env/*.c

all: $(NAME)

$(NAME): $(SRC)
	@echo "Compiling $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)
	@echo "$(NAME) compiled successfully"

clean:
	@echo "Cleaning up..."
	@rm -f $(NAME)
	@echo "Cleaned up $(NAME)"

