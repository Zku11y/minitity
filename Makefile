

NAME = run

SRC = main.c\
	libft/*.c
	m_env/*.c
	m_sig/*.c
	m_bul/*.c

all: $(NAME)

$(NAME): $(SRC)
	@echo "Compiling $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)
	@echo "$(NAME) compiled successfully"

clean:
	@echo "Cleaning up..."
	@rm -f $(NAME)
	@echo "Cleaned up $(NAME)"
