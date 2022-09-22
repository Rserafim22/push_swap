NAME = push_swap
CC = cc
RM = rm -rf
LIB = ./libft
LIBFT	= ./libft/libft.a
SRC = main.c \
				list_utils.c \
				list_utils2.c \
				stack_check.c \
				chunk.c \
				chunk2.c \
				errors.c \
				extension.c \
				command1.c \
				command2.c \
				value_finder.c \
				main_utils.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB)
	@$(CC) -Wall -Wextra -Werror -o $(NAME) $(OBJ) $(LIBFT)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIB) clean

fclean: clean
	@$(MAKE) -C ./libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
