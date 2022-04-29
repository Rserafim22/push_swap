NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = -L ./Libft -lft
SRC = main.c \
				list_utils.c \
				list_utils2.c \
				stack_check.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
